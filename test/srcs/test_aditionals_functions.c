/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_aditionals_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:32:08 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/23 14:37:11 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

void	test_substr(char const *s, unsigned int start, size_t len, char *exp)
{
	char	*result;

	result = ft_substr(s, start, len);
	printf("%s", get_color_test(exp, result, sizeof(char)));
	printf("Function SUBSTR('%s', %d, %zu)\n", s, start, len);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
	free(result);
}

void	test_strjoin(char const *s1, char const *s2, char *exp)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("%s", get_color_test(exp, result, sizeof(char)));
	printf("Function STRJOIN('%s', '%s')\n", s1, s2);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
	free(result);
}

void	test_strtrim(char const *s1, char const *set, char *exp)
{
	char	*result;

	result = ft_strtrim(s1, set);
	printf("%s", get_color_test(exp, result, sizeof(char)));
	printf("Function STRTRIM('%s', '%s')\n", s1, set);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
	free(result);
}

void	test_split(char const *s, char c, char **exp)
{
	char			**result;
	unsigned int	index;

	result = ft_split(s, c);
	index = 0;
	if (!result && !exp)
	{
		printf("%s", get_color_test(exp, result, sizeof(char *)));
		printf("Function SPLIT('%s', '%c')\n", s, c);
		printf("\t-> EXPECTED: (null)\n");
		printf("\t-> RESULT:   (null)\n");
		printf("\033[0m");
		printf("\n");
		return ;
	}
	while (result[index])
	{
		printf("%s", get_color_test(exp[index], result[index], sizeof(char)));
		index++;
	}
	printf("Function SPLIT('%s', '%c')\n", s, c);
	index = 0;
	while (result[index])
	{
		printf("%s", get_color_test(exp[index], result[index], sizeof(char)));
		printf("\t-> EXPECTED[%d]: %s\n", index, exp[index]);
		printf("\t-> RESULT[%d]:   %s\n", index, result[index]);
		printf("\033[0m");
		printf("\n");
		free(result[index]);
		index++;
	}
	free(result);
}

void	test_itoa(int n, char *exp)
{
	char	*result;

	result = ft_itoa(n);
	printf("%s", get_color_test(exp, result, sizeof(char)));
	printf("Function ITOA(%d)\n", n);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
	free(result);
}

void	test_strmapi(char *s, char (*f)(unsigned int, char), char *exp)
{
	char	*result;

	result = ft_strmapi(s, f);
	printf("%s", get_color_test(exp, result, sizeof(char)));
	printf("Function STRMAPI('%s')\n", s);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", result);
	printf("\033[0m");
	printf("\n");
}

void	test_striteri(char *s, void (*f)(unsigned int, char *), char *exp)
{
	ft_striteri(s, f);
	printf("%s", get_color_test(exp, s, sizeof(char)));
	printf("Function STRITERI('%s')\n", s);
	printf("\t-> EXPECTED: %s\n", exp);
	printf("\t-> RESULT:   %s\n", s);
	printf("\033[0m");
}

static char	*read_test_txt(size_t len, size_t aux)
{
	int		fd;
	char	*buffer;
	size_t	bytes_read;

	fd = open("../test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Can't open file\n");
		return (NULL);
	}
	buffer = malloc((len + aux + 1) * sizeof(char));
	if (!buffer)
	{
		printf("%s\n", "No couldn't malloc the buffer");
		return (NULL);
	}
	bytes_read = read(fd, buffer, len + aux + 1);
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
 }

void	test_putchar_fd(char c)
{
	int		fd;
	char	*buffer;
	char	ch[2];

	fd = open("../test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Can't open file\n");
		return ;
	}
	ft_putchar_fd(c, fd);
	close(fd);
	ch[0] = c;
	ch[1] = '\0';
	buffer = read_test_txt(strlen(ch), 0);
	printf("%s", get_color_test(ch, buffer, sizeof(char)));
	printf("Function PUTCHAR_FD('%c')\n", c);
	printf("\t-> EXPECTED: %s\n", ch);
	printf("\t-> RESULT:   %s\n", buffer);
	printf("\033[0m");
	free(buffer);
}

void	test_putstr_fd(char *str)
{
	int		fd;
	char	*buffer;

	fd = open("../test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Can't open file\n");
		return ;
	}
	ft_putstr_fd(str, fd);
	close(fd);
	if(!str)
		buffer = NULL;
	else
		buffer = read_test_txt(strlen(str), 0);
	printf("%s", get_color_test(str, buffer, sizeof(char)));
	printf("Function PUTSTR_FD('%s')\n", str);
	printf("\t-> EXPECTED: %s\n", str);
	printf("\t-> RESULT:   %s\n", buffer);
	printf("\033[0m");
	free(buffer);
}

void	test_putendl_fd(char *str)
{
	int		fd;
	char	*buffer;

	fd = open("../test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Can't open file\n");
		return ;
	}
	ft_putendl_fd(str, fd);
	close(fd);
	if(!str)
		buffer = NULL;
	else
		buffer = read_test_txt(strlen(str), 0);
	printf("%s", get_color_test(str, buffer, sizeof(char)));
	printf("Function PUTENDL_FD('%s')\n", str);
	printf("\t-> EXPECTED: %s\n", str);
	printf("\t-> RESULT:   %s\n", buffer);
	printf("\033[0m");
	free(buffer);
}

void	test_putnbr_fd(int nb)
{
	int		fd;
	char	*buffer;
	int		result;

	fd = open("../test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Can't open file\n");
		return ;
	}
	ft_putnbr_fd(nb, fd);
	close(fd);
	buffer = read_test_txt(99, 1);
	result = atoi(buffer);
	printf("%s", get_color_test((void *)&nb, (void *)&result, sizeof(int)));
	printf("Function PUTNBR_FD(%d)\n", nb);
	printf("\t-> EXPECTED: %d\n", nb);
	printf("\t-> RESULT:   %d\n", result);
	printf("\033[0m");
}
