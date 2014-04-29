# ipv4
# 1 
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.10",
   input => "10.10.10.10",
   ret => 1
},
# 2
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.10",
   input => "10.10.10.11",
   ret => 0
},
# 3
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.0/21",
   input => "10.10.10.11",
   ret => 1
},
# 4
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.0/21",
# min valid: 10.10.8.1 
   input => "10.10.7.254",  
   ret => 0
},
# 5
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.0/21",
   input => "10.10.8.1",
   ret => 1
},
# 6
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.0/21",
# max valid: 10.10.15.254
   input => "10.10.16.1",  
   ret => 0
},
# 7
{
   type => "op",
   name => "ipMatch",
   param => "10.10.10.0/21",
   input => "10.10.15.254",
   ret => 1
},
# 8
{
   type => "op",
   name => "ipMatch",
   param => "192.168.1.0/24",
   input => "192.168.1.254",
   ret => 1
},

# 9
{
   type => "op",
   name => "ipMatch",
   param => "156.149.249.1/8",
   input => "10.10.10.11",
   ret => 1
},
# 10
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/24",
   input => "10.10.10.11",
   ret => 1
},
# 11
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/16",
   input => "10.10.10.11",
   ret => 1
},
# 12
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/8",
   input => "10.10.10.11",
   ret => 1
},
# 13
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/4",
   input => "10.10.10.11",
   ret => 1
},
# 14
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/2",
   input => "10.10.10.11",
   ret => 1
},
# 15
{
   type => "op",
   name => "ipMatch",
   param => "10.0.0.0/100",
   input => "10.10.10.11",
   ret => -1
},

# ipv6
# 16
{
   type => "op",
   name => "ipMatch",
   param => "2001:db8::/32",
   input => "2001:0db8:ffff:ffff:ffff:ffff:ff00:00ff",
   ret => 1
},
# 17
{
   type => "op",
   name => "ipMatch",
   param => "2001:db8::/63",
   input => "2001:0db8:ffff:ffff:ffff:ffff:ff00:00ff",
   ret => 0
},

