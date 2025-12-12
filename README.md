*This project has been created as part of the 42 curriculum by yanlu.*

# Description
This project creates the function `get_next_line()` to read from a file descriptor line by line.

- Language: C
- Prototype: `char *get_next_line(int fd);`
- Param: fd: The file descriptor to read from.
- Return: The line that was read. NULL if there is nothing left to read, or if an error occurs.

# Instructions
Use this function by including the files in this repo in your working path and include its header in your code:

    #include "get_next_line.h"

Compile with:

    cc -Wall -Wextra -Werror <files>.c get_next_line.c get_next_line_utils.c

to read with the default buffer size (replace \<files\> with the names of the other files you want to compile),
or:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

for a user defined buffer size (replace 42 with any number).

Example usage:

    ft_printf("Hello world%c%i", '!', 1);

prints out:

    Hello world!1

# Resources
- [Tutorial for file descriptors](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Tutotial for static variables](https://www.geeksforgeeks.org/c/static-variables-in-c/)

AI was not used for this project.