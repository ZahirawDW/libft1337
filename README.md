*This project has been created as part of the 42 curriculum by zel-mahj.*

# Libft

## Description

Libft is a C library that I built from scratch as my first project at 42.
The goal is to understand how common C functions work by reimplementing them
myself, while practicing memory management (malloc/free), pointers and
header files. The library has three parts: libc functions rewritten with the
`ft_` prefix, additional string and output utilities, and linked list
functions. Everything is compiled into a static library, `libft.a`, that I can
reuse in my future projects.

## Instructions

Compile the library (creates `libft.a` at the root):
```sh
make
```

Other rules:
```sh
make clean   # removes the object files
make fclean  # removes the object files and libft.a
make re      # fclean + all
```

Use it in your own program:
```sh
cc -Wall -Wextra -Werror main.c libft.a
```

The program using the library must include libft.h :
```c
#include "libft.h"
```

## Library contents

**Part 1 - Libc functions:** my own versions of standard functions (ft_strlen, ft_memcpy, ft_atoi, ...).
They follow the man pages, with these differences:

The ft_is* functions return exactly 1 or 0, as the subject requires, while the real ones return any non-zero value.
ft_strncmp and ft_memcmp return the difference between the first differing bytes, and the man pages only guarantee the sign.
Undefined behavior (for example NULL arguments, or overlapping buffers in ft_memcpy) is not handled, and these functions crash like the originals.
ft_atoi has no guaranteed result for numbers that don’t fit in a long.
ft_toupper, ft_tolower and the ft_is* functions work on ASCII only.

**Part 2 - Additional functions:** functions that are not in libc or exist in a
different form (ft_substr, ft_strjoin, ft_split, ft_itoa, ...).

**Part 3 - Linked list:** a t_list structure and functions to create, add,
count, iterate, map and free nodes (ft_lstnew ... ft_lstmap).

The library is built with `ar rcs` into the static library `libft.a`.

## Resources

### References
- Man pages (`man 3 <function>`): behavior of each libc function
- GNU Make manual: Makefile rules and variables
- YouTube : pointers, malloc/free, Makefile
- GeeksforGeeks: C string and memory functions, linked lists

### Use of AI
I used Claude (AI assistant) as a learning tool, not to write my functions:
- to explain concepts (libft.h, static vs dynamic libraries, how a Makefile works)
- to quiz me on the functions so I could understand them
- to help me structure and write this README
The code of the library was written by me.