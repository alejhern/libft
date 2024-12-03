/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_man_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:49:52 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/23 14:37:48 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

void	test_atoi(char *nb)
{
	long	expected;
	long	result;

	expected = atoi(nb);
	result = ft_atoi(nb);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ATOI('%s')\n", nb);
	printf("\t-> EXPECTED: %ld\n", expected);
	printf("\t-> RESULT:   %ld\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_bzero(char *s, size_t size)
{
	char	expected[256];
	char	result[256];

	strncpy(expected, s, 255);
	expected[255] = '\0';
	strncpy(result, s, 255);
	result[255] = '\0';
	bzero(expected, size);
	ft_bzero(result, size);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function BZERO('%s', %zu)\n", s, size);
	printf("\t-> EXPECTED: %p\n", expected);
	printf("\t-> RESULT:   %p\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_calloc(size_t nmemb, size_t size)
{
	void	*expected;
	void	*result;

	expected = calloc(nmemb, size);
	result = ft_calloc(nmemb, size);
	printf("%s", get_color_test(expected, result, nmemb * size));
	printf("Function CALLOC(%zu, %zu)\n", nmemb, size);
	printf("\t-> EXPECTED: %p\n", expected);
	printf("\t-> RESULT:   %p\n", result);
	printf("\033[0m");
	printf("\n");
	free(expected);
	free(result);
}

void	test_isalnum(int c)
{
	int	expected;
	int	result;

	expected = isalnum(c);
	result = ft_isalnum(c);
	if (expected > 0)
		expected = 1;
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ISALNUM('%c')\n", (char)c);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_isalpha(int c)
{
	int	expected;
	int	result;

	expected = isalpha(c);
	result = ft_isalpha(c);
	if (expected > 0)
		expected = 1;
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ISALPHA('%c')\n", (char)c);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_isascii(int c)
{
	int	expected;
	int	result;

	expected = isascii(c);
	result = ft_isascii(c);
	if (expected > 0)
		expected = 1;
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ISASCII('%c')\n", c);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_isdigit(int c)
{
	int	expected;
	int	result;

	expected = isdigit(c);
	result = ft_isdigit(c);
	if (expected > 0)
		expected = 1;
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ISDIGIT('%c')\n", (char)c);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_isprint(int c)
{
	int	expected;
	int	result;

	expected = isprint(c);
	result = ft_isprint(c);
	if (expected > 0)
		expected = 1;
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function ISPRINT('%c')\n", (char)c);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_memchr(void *s, char c, size_t n)
{
	unsigned char	*expected;
	unsigned char	*result;

	expected = (unsigned char *)memchr(s, c, n);
	result = (unsigned char *)ft_memchr(s, c, n);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function MEMCHR('%s', '%c', %zu)\n", (char *)s, c, n);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_memcmp(char *s1, char *s2, size_t n)
{
	int	expected;
	int	result;

	expected = memcmp(s1, s2, n);
	result = ft_memcmp(s1, s2, n);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function MEMCMP('%s', '%s', %zu)\n", s1, s2, n);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_memcpy(char *s, char *d, size_t size)
{
	char	expected[256];
	char	result[256];

	strncpy(expected, d, 255);
	expected[255] = '\0';
	strncpy(result, d, 255);
	result[255] = '\0';
	memcpy(expected, s, size);
	ft_memcpy(result, s, size);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function MEMCPY('%s', '%s', %zu)\n", s, d, size);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_memmove(char *s1, char *s2, size_t n)
{
	char	expected[256];
	char	result[256];

	strncpy(expected, s1, 255);
	expected[255] = '\0';
	strncpy(result, s1, 255);
	result[255] = '\0';
	memmove(expected, s2, n);
	ft_memmove(result, s2, n);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function MEMMOVE('%s', '%s', %zu)\n", s1, s2, n);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_memset(char *s, int c, size_t size)
{
	char	expected[256];
	char	result[256];

	strncpy(expected, s, 255);
	expected[255] = '\0';
	strncpy(result, s, 255);
	result[255] = '\0';
	memset(expected, c, size);
	ft_memset(result, c, size);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function MEMSET('%s', '%c', %zu)\n", s, (char)c, size);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_strchr(char *str, char c)
{
	char	*expected;
	char	*result;

	expected = strchr(str, c);
	result = ft_strchr(str, c);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRCHR('%s', '%c')\n", str, c);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_strdup(char *str)
{
	char	*expected;
	char	*result;

	expected = strdup(str);
	result = ft_strdup(str);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRDUP('%s')\n", str);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
	free(expected);
	free(result);
}

void	test_strlen(char *str)
{
	int	expected;
	int	result;

	expected = strlen(str);
	result = ft_strlen(str);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function STRLEN('%s')\n", str);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_strlcat(char *dest, char *src, size_t n)
{
	int		exp;
	int		res;
	char	expected[256];
	char	result[256];

	strncpy(expected, dest, 255);
	expected[255] = '\0';
	strncpy(result, dest, 255);
	result[255] = '\0';
	exp = strlcat(expected, src, n);
	res = ft_strlcat(result, src, n);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRLCAT('%s', '%s', %zu)\n", dest, src, n);
	printf("\t-> EXPECTED: %d CADENA: %s\n", exp, expected);
	printf("\t-> RESULT:   %d CADENA: %s\n", res, result);
	printf("\033[0m");
	printf("\n");
}

void	test_strlcpy(char *dest, char *src, size_t n)
{
	int		exp;
	int		res;
	char	expected[256];
	char	result[256];

	strncpy(expected, dest, 255);
	expected[255] = '\0';
	strncpy(result, dest, 255);
	result[255] = '\0';
	exp = strlcpy(expected, src, n);
	res = ft_strlcpy(result, src, n);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRLCPY('%s', '%s', %zu)\n", dest, src, n);
	printf("\t-> EXPECTED: %d CADENA: %s\n", exp, expected);
	printf("\t-> RESULT:   %d CADENA: %s\n", res, result);
	printf("\033[0m");
	printf("\n");
}

void	test_strncmp(char *s1, char *s2, size_t n)
{
	int	expected;
	int	result;

	expected = strncmp(s1, s2, n);
	result = ft_strncmp(s1, s2, n);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function STRNCMP('%s', '%s', %zu)\n", s1, s2, n);
	printf("\t-> EXPECTED: %d\n", expected);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_strnstr(char *str, char *to_find, size_t len)
{
	char	*expected;
	char	*result;

	expected = strnstr(str, to_find, len);
	result = ft_strnstr(str, to_find, len);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRNSTR('%s', '%s', %zu)\n", str, to_find, len);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_strrchr(char *str, char c)
{
	char	*expected;
	char	*result;

	expected = strrchr(str, c);
	result = ft_strrchr(str, c);
	printf("%s", get_color_test(expected, result, sizeof(char)));
	printf("Function STRRCHR('%s', '%c')\n", str, c);
	printf("\t-> EXPECTED: %s\n", expected);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_tolower(int c)
{
	int	expected;
	int	result;

	expected = tolower(c);
	result = ft_tolower(c);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function TOLOWER(%c)\n", (unsigned char)c);
	printf("\t-> EXPECTED: %c\n", (unsigned char)expected);
	printf("\t-> RESULT:   %c\n", (unsigned char)result);
	printf("\033[0m");
	printf("\n");
}

void	test_toupper(int c)
{
	int	expected;
	int	result;

	expected = toupper(c);
	result = ft_toupper(c);
	printf("%s", get_color_test((void *)&expected, (void *)&result,
			sizeof(int)));
	printf("Function TOUPPER(%c)\n", (unsigned char)c);
	printf("\t-> EXPECTED: %c\n", (unsigned char)expected);
	printf("\t-> RESULT:   %c\n", (unsigned char)result);
	printf("\033[0m");
	printf("\n");
}
