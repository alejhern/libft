/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:15:15 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/23 14:34:39 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../test.h"

void	test_1(void)
{
	print_title("Testing ft_atoi");
	test_atoi("123456");
	test_atoi("-78910");
	test_atoi("0");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("99999999999999");
	test_atoi("-99999999999999");
	print_title("Testing ft_bzero");
	test_bzero("Expecto Patronum!", 8);
	test_bzero("Hakuna Matata.", 5);
	test_bzero("I am Iron Man.", 10);
	test_bzero("May the Force be with you.", 0);
	print_title("Testing ft_calloc");
	test_calloc(6, sizeof(int));
	test_calloc(0, sizeof(double));
	test_calloc(3, sizeof(char));
	test_calloc(9, sizeof(long));
	print_title("Testing ft_isalnum");
	test_isalnum('A');
	test_isalnum('5');
	test_isalnum('*');
	test_isalnum(' ');
	print_title("Testing ft_isalpha");
	test_isalpha('D');
	test_isalpha('W');
	test_isalpha('E');
	test_isalpha('*');
	print_title("Testing ft_isascii");
	test_isascii('T');
	test_isascii('0');
	test_isascii(65);
	test_isascii(0);
	print_title("Testing ft_isdigit");
	test_isdigit('9');
	test_isdigit('3');
	test_isdigit('N');
	test_isdigit(' ');
	print_title("Testing ft_isprint");
	test_isprint('I');
	test_isprint('W');
	test_isprint('H');
	test_isprint(1);
	print_title("Testing ft_memchr");
	test_memchr("I am Iron Man.", 'M', 5);
	test_memchr("Plus Ultra!", 'U', 10);
	test_memchr("The One Piece is real!", 'P', 20);
	test_memchr("To infinity and beyond!", 'y', 18);
	print_title("Testing ft_memcmp");
	test_memcmp("I am Iron Man.", "I am inevitable.", 8);
	test_memcmp("The One Piece is real!", "Plus Ultra!", 12);
	test_memcmp("To infinity and beyond!", "To the moon and back", 10);
	test_memcmp("With great power comes great responsibility.",
		"With great power comes great responsibility.", 40);
	print_title("Testing ft_memcpy");
	test_memcpy("Hakuna Matata.", "I solemnly swear that I am up to no good.",
		10);
	test_memcpy("I am Iron Man.",
		"With great power comes great responsibility.", 20);
	test_memcpy("May the Force be with you.", "Wingardium Leviosa!", 15);
	test_memcpy("To infinity and beyond!", "Expecto Patronum!", 15);
	print_title("Testing ft_memmove");
	test_memmove("I am Iron Man.",
		"With great power comes great responsibility.", 30);
	test_memmove("I solemnly swear that I am up to no good.", "It's over 9000!",
		15);
	test_memmove("May the Force be with you.", "Expecto Patronum!", 20);
	test_memmove("The One Piece is real!", "Plus Ultra!", 11);
	print_title("Testing ft_memset");
	test_memset("I am Iron Man.", '!', 5);
	test_memset("May the Force be with you.", '*', 18);
	test_memset("To infinity and beyond!", '@', 10);
	test_memset("With great power comes great responsibility.", '#', 25);
	print_title("Testing ft_strchr");
	test_strchr("I am Iron Man.", 'I');
	test_strchr("The One Piece is real!", 'P');
	test_strchr("Plus Ultra!", 'U');
	test_strchr("To infinity and beyond!", 'z');
	print_title("Testing ft_strdup");
	test_strdup("I solemnly swear that I am up to no good.");
	test_strdup("May the Force be with you.");
	test_strdup("To infinity and beyond!");
	test_strdup("With great power comes great responsibility.");
	print_title("Testing ft_strlen");
	test_strlen("I am Iron Man.");
	test_strlen("Plus Ultra!");
	test_strlen("The One Piece is real!");
	test_strlen("To infinity and beyond!");
	print_title("Testing ft_strlcat");
	test_strlcat("I am Iron Man.",
		" With great power comes great responsibility.", 50);
	test_strlcat("To infinity and beyond!", " And beyond!", 30);
	test_strlcat("May the Force be with you.", " Always.", 40);
	test_strlcat("Hakuna Matata.", " It means no worries.", 30);
	print_title("Testing ft_strlcpy");
	test_strlcpy("I am Iron Man.",
		" With great power comes great responsibility.", 50);
	test_strlcpy("To infinity and beyond!", " And beyond!", 30);
	test_strlcpy("May the Force be with you.", " Always.", 40);
	test_strlcpy("Hakuna Matata.", " It means no worries.", 30);
	print_title("Testing ft_strnstr");
	test_strnstr("I solemnly swear that I am up to no good.", "solemnly", 25);
	test_strnstr("May the Force be with you.", "Force", 10);
	test_strnstr("To infinity and beyond!", "beyond", 18);
	test_strnstr("With great power comes great responsibility.", "power", 20);
	print_title("Testing ft_strncmp");
	test_strncmp("I am Iron Man.", "I am inevitable.", 8);
	test_strncmp("The One Piece is real!", "Plus Ultra!", 12);
	test_strncmp("To infinity and beyond!", "To the moon and back", 10);
	test_strncmp("With great power comes great responsibility.",
		"With great power comes great responsibility.", 40);
	print_title("Testing ft_strrchr");
	test_strrchr("I am Iron Man.", 'I');
	test_strrchr("May the Force be with you.", 'z');
	test_strrchr("To infinity and beyond!", 'n');
	test_strrchr("With great power comes great responsibility.", 'r');
	print_title("Testing ft_tolower");
	test_tolower('A');
	test_tolower('S');
	test_tolower('W');
	test_tolower('7');
	print_title("Testing ft_toupper");
	test_toupper('a');
	test_toupper('i');
	test_toupper('e');
	test_toupper('9');
}
