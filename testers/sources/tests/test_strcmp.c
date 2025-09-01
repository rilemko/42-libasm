/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
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

static void	test_strcmp_1(void)
{
	const char	*s1;
	const char	*s2;
	int			result;
	int			expected;

	s1 = "Hello";
	s2 = "Hello";
	result = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	printf("Test 1 (equal): ft_strcmp(\"%s\", \"%s\") = %d, strcmp = %d ",
		s1, s2, result, expected);
	if ((result == 0) == (expected == 0))
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strcmp_2(void)
{
	const char	*s1;
	const char	*s2;
	int			result;
	int			expected;

	s1 = "Hello";
	s2 = "World";
	result = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	printf("Test 2 (less): ft_strcmp(\"%s\", \"%s\") = %d, strcmp = %d ",
		s1, s2, result, expected);
	if ((result < 0) == (expected < 0))
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strcmp_3(void)
{
	const char	*s1;
	const char	*s2;
	int			result;
	int			expected;

	s1 = "World";
	s2 = "Hello";
	result = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	printf("Test 3 (greater): ft_strcmp(\"%s\", \"%s\") = %d, strcmp = %d ",
		s1, s2, result, expected);
	if ((result > 0) == (expected > 0))
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strcmp_4(void)
{
	const char	*s1;
	const char	*s2;
	int			result;
	int			expected;

	s1 = "";
	s2 = "";
	result = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	printf("Test 4 (empty): ft_strcmp(\"\", \"\") = %d, strcmp = %d ",
		result, expected);
	if ((result == 0) == (expected == 0))
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	test_strcmp(void)
{
	printf("\n=== TEST FT_STRCMP ===\n");
	test_strcmp_1();
	test_strcmp_2();
	test_strcmp_3();
	test_strcmp_4();
}
