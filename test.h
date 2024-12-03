#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

// Declarations from strlcat.c
size_t	strlcat(char *dst, const char *src, size_t dsize);
// Declarations from strlcpy.c
size_t	strlcpy(char *dst, const char *src, size_t siz);
// Declarations from strnstr.c
char	*strnstr(const char *s, const char *find, size_t slen);
// Declarations from test_aditionals_functions.c
void	test_substr(char const *s, unsigned int start, size_t len, char *exp);
void	test_strjoin(char const *s1, char const *s2, char *exp);
void	test_strtrim(char const *s1, char const *set, char *exp);
void	test_split(char const *s, char c, char **exp);
void	test_itoa(int n, char *exp);
void	test_strmapi(char *s, char (*f)(unsigned int, char), char *exp);
void	test_striteri(char *s, void (*f)(unsigned int, char *), char *exp);
void	test_putchar_fd(char c);
void	test_putstr_fd(char *str);
void	test_putendl_fd(char *str);
void	test_putnbr_fd(int nb);
// Declarations from test_man_functions.c
void	test_atoi(char *nb);
void	test_bzero(char *s, size_t size);
void	test_calloc(size_t nmemb, size_t size);
void	test_isalnum(int c);
void	test_isalpha(int c);
void	test_isascii(int c);
void	test_isdigit(int c);
void	test_isprint(int c);
void	test_memchr(void *s, char c, size_t n);
void	test_memcmp(char *s1, char *s2, size_t n);
void	test_memcpy(char *s, char *d, size_t size);
void	test_memmove(char *s1, char *s2, size_t n);
void	test_memset(char *s, int c, size_t size);
void	test_strchr(char *str, char c);
void	test_strdup(char *str);
void	test_strlen(char *str);
void	test_strlcat(char *dest, char *src, size_t n);
void	test_strlcpy(char *dest, char *src, size_t n);
void	test_strncmp(char *s1, char *s2, size_t n);
void	test_strnstr(char *str, char *to_find, size_t len);
void	test_strrchr(char *str, char c);
void	test_tolower(int c);
void	test_toupper(int c);
// Declarations from main.c
int     main(int argc, char **argv);
// Declarations from utils_main.c
char	*get_color_test(void *expected, void *result, size_t size);
void	print_title(const char *title);
// Declarations from test_1.c
void	test_1(void);
// Declarations from test_2.c
void	test_2(void);

#endif
