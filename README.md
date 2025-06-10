# 🧭Libft - C Function Library

## ✨ Introduction
`libft` is a C library that implements a set of useful functions for string manipulation, memory management, linked lists, and other common operations. It is an essential tool for any programmer looking to strengthen their C skills and optimize project development.

---

## 🔍 Project Structure

The project is organized into multiple C files, each containing specific functions grouped by category. Below is a detailed description of the available functions in `libft.h`.

---

## 📊 Included Functions

### 1. 🪄 Array Modifications
- `ft_free_array(void ***array)`: Frees a dynamically allocated array.
  - **Example:**
    ```c
    ft_free_array((void ***)&arr);
    ```
- `ft_free_func_array(void ***array, void (*f)(void *))`: Frees a dynamically allocated array using a custom function.
  - **Example:**
    ```c
    ft_free_func_array((void ***)&arr, mlx_delete_texture);
    ```
- `ft_rotate_array(void ***array)`: Rotates the array forward (moves elements to the right).
  - **Example:**
    ```c
    ft_rotate_array((void ***)&arr);
    ```
- `ft_rotate_rev_array(void ***array)`: Rotates the array backward (moves elements to the left).
  - **Example:**
    ```c
    ft_rotate_rev_array((void ***)&arr);
    ```
- `ft_append_array(void ***array, void *new_element)`: Adds a new element to a dynamically allocated array.
  - **Example:**
    ```c
    char **arr = NULL;
    ft_append_array((void ***)&arr, ft_strdup("Hello"));
    ft_append_array((void ***)&arr, ft_strdup("World"));
    ```

### 2. ♻️ Character and String Conversion
- `ft_atoi(const char *str)`: Converts a string to an integer.
- `ft_atol(const char *str)`: Converts a string to a long integer.
- `ft_nblen(int nb)`: Returns the length of a number in characters.
- `ft_itoa(int nb)`: Converts an integer to a string.
- `ft_itoa_base(unsigned long long nb, int base)`: Converts a number to a string in a specified base.
- `ft_tolower(int c)`: Converts a character to lowercase.
- `ft_toupper(int c)`: Converts a character to uppercase.

### 3. 📖 File Handling and Reading 
- `get_next_line(int fd)`: Reads the next line from a file descriptor. This function is useful for processing files line by line efficiently.

### 4. ✍️ Input and Output
- `ft_printf(const char *str, ...)`: Prints a formatted string to the standard output.
- `ft_printf_fd(int fd, const char *str, ...)`: Prints a formatted string to a file descriptor.
- `ft_putchar_fd(char c, int fd)`: Writes a character to a file descriptor.
- `ft_putendl_fd(char *s, int fd)`: Writes a string with a newline to a file descriptor.
- `ft_putnbr_fd(int nbr, int fd)`: Writes a number to a file descriptor.
- `ft_putstr_fd(char *s, int fd)`: Writes a string to a file descriptor.

### 5. 🔗 Linked Lists
- `ft_lstadd_back(t_list **lst, t_list *new)`: Adds a node at the end of the list.
- `ft_lstadd_front(t_list **lst, t_list *new)`: Adds a node at the beginning of the list.
- `ft_lstclear(t_list **lst, void (*del)(void *))`: Deletes all nodes from the list.
- `ft_lstdelone(t_list *lst, void (*del)(void *))`: Deletes a node from the list.
- `ft_lstiter(t_list *lst, void (*f)(void *))`: Iterates through the list and applies a function.
- `ft_lstlast(t_list *lst)`: Returns the last node of the list.
- `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`: Creates a new list by applying a function to each node.
- `ft_lstnew(void *content)`: Creates a new list node.
- `ft_lstsize(t_list *lst)`: Returns the size of the list.

### 6. 🧠 Memory Manipulation
- `ft_bzero(void *s, size_t len)`: Fills a memory block with zeros.
- `ft_calloc(size_t nmemb, size_t size)`: Allocates memory and initializes it to 0.
- `ft_memchr(const void *s, int c, size_t n)`: Searches for a character in a memory region.
- `ft_memcmp(const void *s1, const void *s2, size_t n)`: Compares two memory blocks.
- `ft_memcpy(void *dest, const void *src, size_t n)`: Copies data from one memory region to another.
- `ft_memlen(const void *ptr)`: Returns the length of a memory block.
- `ft_memmove(void *dest, const void *src, size_t n)`: Safely copies data in memory regions that may overlap.
- `ft_memset(void *dest, int c, size_t len)`: Fills a memory block with a specific value.
- `ft_realloc(void *ptr, size_t new_size)`: Resizes a memory block.

### 7. 🕹️ 2D Position Functions
- `ft_pos_add(t_pos a, t_pos b)`: Adds two `t_pos` structures.
- `ft_pos_cmp(t_pos a, t_pos b)`: Compares two `t_pos` structures.
- `ft_pos_distance(t_pos a, t_pos b)`: Calculates the distance between two positions.
- `ft_pos_sub(t_pos a, t_pos b)`: Subtracts two `t_pos` structures.

### 8. ✂️ String Manipulation
- `ft_split(const char *s, char c)`: Splits a string into an array of strings based on a delimiter.
- `ft_strappend(char *dest, char *to_append)`: Appends one string to another.
- `ft_strchr(const char *str, int c)`: Searches for a character in a string.
- `ft_strdup(const char *str)`: Duplicates a string.
- `ft_striteri(char *s, void (*f)(unsigned int, char *))`: Applies a function to each character of a string with an index.
- `ft_strjoin(const char *s1, const char *s2)`: Joins two strings.
- `ft_strlcat(char *dest, const char *src, size_t nb)`: Concatenates strings with size limitation.
- `ft_strlcpy(char *dest, const char *src, size_t size)`: Copies a string with size limitation.
- `ft_strlen(const char *str)`: Calculates the length of a string.
- `ft_strmapi(const char *s, char (*f)(unsigned int, char))`: Applies a function to each character of a string.
- `ft_strncmp(const char *s1, const char *s2, size_t n)`: Compares two strings up to a given number of characters.
- `ft_strnstr(const char *big, const char *little, size_t len)`: Searches for a substring within a string.
- `ft_strrchr(const char *str, int c)`: Searches for a character in a string from the end.
- `ft_strtrim(const char *s1, const char *set)`: Removes specified characters from the edges of a string.
- `ft_substr(const char *s, unsigned int start, size_t len)`: Extracts a substring.

### 9. 🚨 Functions for Error Handling
- `ft_error_exit(const char *msg)`: Prints an error message and immediately terminates the program execution.
- `ft_func_error_exit(const char *msg, void **param, void *(f)(void *))`: Executes a function before terminating the program.
- `ft_perror_exit(const char *msg)`: Prints an error message followed by the standard error (errno) and terminates the program execution.

### 10. 🌍 Environment Variable Management and Execution
- `ft_env(const char **env)`: Copies the system environment variables into a dynamically allocated array.
- `ft_getenv(const char *name, char **env)`: Retrieves the value of an environment variable.
- `ft_unsetenv(const char *name, char ***env)`: Removes an environment variable from the array.
- `ft_setenv(const char *name, const char *value, char ***env)`: Adds or updates an environment variable in the array.
- `ft_execute(char *line, char **env, int make_fork)`: Executes a command line.
- `ft_exec_catch(const char *cmd)`: Executes a system command (such as ls, whoami, etc.) and captures its standard output (stdout), returning the result as a string (char *).
- `ft_pipe(int input_fd, char **cmd, char **env);`: Executes a comand line in a pipe.

---

## 🛠 Data Structures
- `t_list`: A linked list structure containing a `void *content` and a pointer to the next node.
- `t_pos`: A structure representing a 2D position with integer coordinates `x` and `y`.

---

## 🛠 Installation and Usage
To use `libft`, simply compile it and add it to your project:
```bash
make
```
Then, include `libft.h` in your code and link the library:
```c
#include "libft.h"
```

---

## ✨ Contribution
If you would like to improve the library, feel free to fork and submit a pull request. All contributions are welcome!

---

## 🎉 Credits
Developed by Alejandro Hernández. Thank you for using `libft`! 🚀