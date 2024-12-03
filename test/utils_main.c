/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:59:52 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/23 14:35:11 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../test.h"

char	*get_color_test(void *expected, void *result, size_t size)
{
	// Secuencias de escape ANSI para colores
	char *red = "\033[1;31m";
	char *green = "\033[1;32m";
    if (!expected && !result)
        return (green);
    if (size == sizeof(int))
    {
        int *exp = (int *)expected;
        int *res = (int *)result;
        if (*exp == *res)
            return (green);
        else
            return (red);
    }
	if (memcmp(expected, result, size) == 0)
		return (green);
	else
		return (red);
}

void print_title(const char *title)
{
    int len = strlen(title);
    int width = 50; // Width of the square box

    printf("\n");
    printf("\033[38;5;214m"); // Set text color to blue
    printf("╔");
    for (int i = 0; i < width - 2; ++i) printf("═");
    printf("╗\n");

	// Print empty line
    printf("║");
    for (int i = 0; i < width - 2; ++i) printf(" ");
    printf("║\n");

    // Print title with center alignment
    printf("║");
    int padding = (width - 2 - len) / 2;
    for (int i = 0; i < padding; ++i) printf(" ");
    printf("%s", title);
    for (int i = 0; i < padding; ++i) printf(" ");
    if ((width - 2 - len) % 2 != 0) printf(" ");
    printf("║\n");

    // Print empty line
    printf("║");
    for (int i = 0; i < width - 2; ++i) printf(" ");
    printf("║\n");

    // Print bottom border
    printf("╚");
    for (int i = 0; i < width - 2; ++i) printf("═");
    printf("╝\n");

    printf("\033[0m"); // Reset text color
	printf("\n");
}
