/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:14:55 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/23 14:34:52 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../test.h"

static void striteri_func(unsigned int i, char *c)
{
		*c = *c + i;
}

static char strmapi_func(unsigned int i, char c)
{
	return (c + i);
}

void	test_2(void)
{
	// Test for ft_substr
	print_title("Testing ft_substr");
	test_substr("It does not do to dwell on dreams", 12, 2, "do");
	test_substr("Happiness can be found", 0, 9, "Happiness");
	test_substr("I solemnly swear that I am up to no good", 2, 7, "solemnly");
	test_substr("After all this time? Always.", 12, 6, "is tim");
	test_substr("Working hard is important. But there is something that matters even more: believing in yourself.", 15, 8, " importa");
	test_substr(NULL, 0, 5, NULL); // NULL string

	// Test for ft_join
	print_title("Testing ft_strjoin");
	test_strjoin("I open at the ", "close", "I open at the close");
	test_strjoin("Mischief ", "Managed", "Mischief Managed");
	test_strjoin("Yer a ", "wizard, Harry", "Yer a wizard, Harry");
	test_strjoin("", "Expecto Patronum", "Expecto Patronum");
	test_strjoin("The ones that love us ", "never really leave us", "The ones that love us never really leave us");
	test_strjoin(NULL, "Expecto Patronum", "Expecto Patronum"); // NULL first string
	test_strjoin("Expecto Patronum", NULL, "Expecto Patronum"); // NULL second string

	// Test for ft_trim
	print_title("Testing ft_strtrim");
	test_strtrim("  I am what I am, an Albus Dumbledore  ", " ", "I am what I am, an Albus Dumbledore");
	test_strtrim("###It does not do to dwell on dreams###", "#", "It does not do to dwell on dreams");
	test_strtrim("Happiness can be found", " ", "Happiness can be found");
	test_strtrim("...It is our choices that show what we truly are, far more than our abilities...", ".", "It is our choices that show what we truly are, far more than our abilities");
	test_strtrim("***Turn to page 394***", "*", "Turn to page 394");
	test_strtrim(NULL, " ", NULL); // NULL string
	test_strtrim("Hogwarts", NULL, NULL); // NULL set of characters

	// Test for ft_split
	print_title("Testing ft_split");
	char *expected1[] = {"Yer", "a", "wizard,", "Harry", NULL};
	test_split("Yer a wizard, Harry", ' ', expected1);
	char *expected2[] = {"I", "solemnly", "swear", "that", "I", "am", "up", "to", "no", "good", NULL};
	test_split("I solemnly swear that I am up to no good", ' ', expected2);
	char *expected3[] = {"After all this time", " Always.", NULL};
	test_split("After all this time? Always.", '?', expected3);
	char *expected4[] = {"I am what I am", " an Albus Dumbledore", NULL};
	test_split("I am what I am, an Albus Dumbledore", ',', expected4);
	char *expected5[] = {"Turn", "o page 394", NULL};
	test_split("Turn to page 394", 't', expected5);
	test_split(NULL, ' ', NULL); // NULL string

	// Test for ft_itoa
	print_title("Testing ft_itoa");
	test_itoa(101, "101");
	test_itoa(-101, "-101");
	test_itoa(0, "0");
	test_itoa(INT_MAX, "2147483647");
	test_itoa(INT_MIN, "-2147483648");
	test_itoa(12345, "12345");
	test_itoa(-67890, "-67890");
	test_itoa(-1, "-1");  // Negative single digit
	test_itoa(9999, "9999"); // Positive four digit number

	// Test for ft_strmapi
	print_title("Testing ft_strmapi");
	test_strmapi("Potter", strmapi_func, "Pqvwtf");
	test_strmapi("Hogwarts", strmapi_func, "Hplzxcvu");
	test_strmapi("Dobby", strmapi_func, "Dqfga");
	test_strmapi("Lumos", strmapi_func, "Lvnqt");
	test_strmapi("Nox", strmapi_func, "Nrz");
	test_strmapi(NULL, strmapi_func, NULL); // NULL string
	test_strmapi("A", NULL, NULL); // NULL function pointer

	// Test for ft_striteri
	print_title("Testing ft_striteri");
	char striteri_test1[] = "Lumos";
	test_striteri(striteri_test1, striteri_func, "Lvnqt");
	char striteri_test2[] = "Nox";
	test_striteri(striteri_test2, striteri_func, "Nrz");
	char striteri_test3[] = "Dobby";
	test_striteri(striteri_test3, striteri_func, "Dqfga");
	char striteri_test4[] = "Hogwarts";
	test_striteri(striteri_test4, striteri_func, "Hplzxcvu");
	char striteri_test5[] = "Expecto";
	test_striteri(striteri_test5, striteri_func, "Eymrvyr");
	test_striteri(NULL, striteri_func, NULL); // NULL string
	test_striteri(striteri_test5, NULL, striteri_test5); // NULL function pointer

	// Test for ft_putchar_fd
	print_title("Testing ft_putchar_fd");
	test_putchar_fd('H');
	test_putchar_fd('P');
	test_putchar_fd('!');
	test_putchar_fd('7');
	test_putchar_fd('\0'); // Testing with null character

	// Test for ft_putstr_fd
	print_title("Testing ft_putstr_fd");
	test_putstr_fd("Happiness can be found");
	test_putstr_fd("It does not do to dwell on dreams");
	test_putstr_fd("Turn to page 394");
	test_putstr_fd("Expecto Patronum");
	test_putstr_fd(NULL); // NULL string

	// Test for ft_putendl_fd
	print_title("Testing ft_putendl_fd");
	test_putendl_fd("It does not do to dwell on dreams");
	test_putendl_fd("I solemnly swear that I am up to no good");
	test_putendl_fd("After all this time? Always.");
	test_putendl_fd("Yer a wizard, Harry");
	test_putendl_fd(NULL); // NULL string

	// Test for ft_putnbr_fd
	print_title("Testing ft_putnbr_fd");
	test_putnbr_fd(101);
	test_putnbr_fd(-101);
	test_putnbr_fd(0);
	test_putnbr_fd(INT_MAX);
	test_putnbr_fd(INT_MIN);
	test_putnbr_fd(42);
	test_putnbr_fd(-42);
	test_putnbr_fd(123456789); // Positive large number
	test_putnbr_fd(-123456789); // Negative large number
}
