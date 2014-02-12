/*
 * ModSecurity for Apache 2.x, http://www.modsecurity.org/
 * Copyright (c) 2004-2014 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <string.h>

#include "msc_escape.h"
#include "msc_util.h"


/**
 * @brief Escape different sets of characteres in a given string.
 *
 * Escape strings. msc_escape can be used to escape characters from different
 * sets, including:
 *
 *  - MSC_ESCAPE_REGEXP: . + [ ] ( ) ? /
 *  - MSC_ESCAPE_QUOTES: "
 *  - MSC_ESCAPE_COLON: :
 *  - MSC_ESCAPE_SPECIAL: \b \n \r \t \v \\
 *                        (Special also includes all characteres bigger than
 *                        0x7f or smaller than 0x1f)
 *
 * If called with `buff_length` set to 0 or with `buff` set to NULL, it will
 * _not_ fill any buffer, instead, it will return the length, that the
 * escaped string will have. This can be used to precisely inform the size of
 * memory that should be allocated to store the espcaped string.
 *
 * @warning strings most be NULL-terminated.
 * @note memory management is the responsability of the caller.
 * @note opt set to 0 means that nothing will be escaped.
 *
 * @param string string to be parsed.
 * @param buff pointer to the destination buffer.
 * @param buff_length length that will fully fill the buffer.
 * @param opt What characters should be escaped:
 * @retval -1 Buffer was not big enought to handle the escaped string.
 * @retval n>0 size of the escaped string.
 *
 */
int msc_escape(const char *string, char *buff, const size_t buff_length,
        const int opt)
{
    int i = 0;
    int length_only = 0;
    int escaped_string_length = 0; 

    if (!buff || !buff_length)
        length_only = 1;

    for (i = 0; i < strlen(string); i++) {
        int to_escape = 0;
        int to_transform = 0;

        switch (string[i]) {
            case ':' :
                if (opt & MSC_ESCAPE_COLON)
                    to_escape = 1;
                break;
           case '"' :
                if (opt & MSC_ESCAPE_QUOTES)
                    to_escape = 1;
                break;
            case '.' :
            case '+' :
            case '[' :
            case ']' :
            case '(' :
            case ')' :
            case '?' :
            case '/' :
                if (opt & MSC_ESCAPE_REGEXP)
                    to_escape = 1;
                break;
            case '\b' :
            case '\n' :
            case '\r' :
            case '\t' :
            case '\v' :
            case '\\' :
                if (opt & MSC_ESCAPE_SPECIAL)
                    to_escape = 1;
                break;
           default:
                if ((opt & MSC_ESCAPE_SPECIAL) &&
                        ((string[i] <= 0x1f) || (string[i] >= 0x7f)))
                    to_transform = 1;
                break;
        }
 

        if (to_escape)
            escaped_string_length += 2;
        else if (to_transform)
            escaped_string_length += 4;
        else
            escaped_string_length += 1;

        if (!length_only) {
            if (escaped_string_length > buff_length)
                goto failed_not_enough_space;

            if (to_escape || to_transform)
                *buff++ = '\\';

            if (to_transform) {
                *buff++ = 'x';
                msc_c2x(string[i], buff);
            }

            *buff++ = string[i];
        }
    }

    if (!length_only) {
        if (escaped_string_length > buff_length)
            goto failed_not_enough_space;

        *buff = '\0';
    }

    return escaped_string_length + 1 /* +1 for the null terminator */;

failed_not_enough_space:
    return -1;
}

