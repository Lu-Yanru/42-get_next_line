*This project has been created as part of the 42 curriculum by yanlu.*

# Description
This project creates the function `get_next_line()` to read from a file descriptor line by line.

- Language: C
- Prototype: `char *get_next_line(int fd);`
- Param: fd: The file descriptor to read from.
- Return: The line that was read. NULL if there is nothing left to read, or if an error occurs.

The `get_next_line()` function in the files ending with `_bonus.{c/h}` allows reading from multiple files simultaneously.

# Instructions
Use this function by including the files in this repo in your working path and include its header in your code:

    #include "get_next_line(_bonus).h"

Compile with:

    cc -Wall -Wextra -Werror <files>.c get_next_line(_bonus).c get_next_line_utils(_bonus).c

to read with the default buffer size (replace \<files\> with the names of the other files you want to compile),
or:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c get_next_line(_bonus).c get_next_line_utils(_bonus).c

for a user defined buffer size (replace 42 with any number).

Example usage:

    char    *line = get_next_line(0);

reads the first line (until including `\n`) from the standard input and stores it in the variable `line`.

# Resources
- [Tutorial for file descriptors](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Tutotial for static variables](https://www.geeksforgeeks.org/c/static-variables-in-c/)

AI was not used for this project.