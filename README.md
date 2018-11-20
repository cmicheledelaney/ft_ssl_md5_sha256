# ft_ssl_md5_sha256

This is an early school project from 42 Silicon Valley. Like with all our projects we were not supposed to use the C Standard Library (some exceptions like malloc, free, read and write), hence my own version of the C Standard Library, or at least parts of it, libft.
The application is a re-implementation of the MD5 terminal and the openssl SHA256 crypto hashing algorithms.  
This application supports these flags, for MD5 as well as SHA256:  
-p -> reads from Standard input
-r -> reverses the order of the output (hash first, then input)
-q -> quiet; prints only the hash
-s -> for a string as input

#### Installation
run these commands:  
`git clone https://github.com/cmicheledelaney/ft_ssl_md5_sha256`  
`cd ft_ssl_md5_sha256`  
`make`  

#### Run
This is how you run the application:
`ft_ssl command [command opts] [command args]`
for example:  
`ft_ssl md5 -s "foo"`  
which gives this as output:  
md5 ("foo") = acbd18db4cc2f85cedef654fccc4a4d8  
