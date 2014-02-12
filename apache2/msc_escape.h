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

#ifndef _MSC_ESCAPE_H_
#define _MSC_ESCAPE_H_

#define MSC_ESCAPE_REGEXP 2
#define MSC_ESCAPE_QUOTES 4
#define MSC_ESCAPE_COLON 8
#define MSC_ESCAPE_SPECIAL 16

int msc_escape(const char *string, char *buff, const size_t buff_length,
		        const int opt);


#endif /* _MSC_ESCAPE_H_ */

