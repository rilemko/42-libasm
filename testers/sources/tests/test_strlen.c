/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:35:00 by mconreau          #+#    #+#             */
/*   Updated: 2025/09/01 23:11:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <string.h>

static void	test_strlen_1(void)
{
	const char	*test;
	size_t		result;
	size_t		expected;

	test = "";
	result = ft_strlen(test);
	expected = strlen(test);
	printf("Test 1 (empty): ft_strlen(\"\") = %zu, strlen(\"\") = %zu ",
		result, expected);
	if (result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strlen_2(void)
{
	const char	*test;
	size_t		result;
	size_t		expected;

	test = "Hello";
	result = ft_strlen(test);
	expected = strlen(test);
	printf("Test 2 (simple): ft_strlen(\"Hello\") = %zu, ", result);
	printf("strlen(\"Hello\") = %zu ", expected);
	if (result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strlen_3(void)
{
	const char	*test;
	size_t		result;
	size_t		expected;

	test = "This is a very long string to test the function";
	result = ft_strlen(test);
	expected = strlen(test);
	printf("Test 3 (long): ft_strlen(long_str) = %zu, strlen(long_str) = %zu ",
		result, expected);
	if (result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strlen_4(void)
{
	const char	*test;
	size_t		result;
	size_t		expected;

	test = "Hello\tWorld\n42!";
	result = ft_strlen(test);
	expected = strlen(test);
	printf("Test 4 (special): ft_strlen(special_chars) = %zu, ",
		result);
	printf("strlen(special_chars) = %zu ", expected);
	if (result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	test_strlen(void)
{
	printf("\n=== TEST FT_STRLEN ===\n");
	test_strlen_1();
	test_strlen_2();
	test_strlen_3();
	test_strlen_4();
}
