/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
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
#include <stdlib.h>

static void	test_strdup_1(void)
{
	const char	*src;
	char		*result;
	char		*expected;

	src = "";
	result = ft_strdup(src);
	expected = strdup(src);
	printf("Test 1 (empty): ft_strdup(\"\") = \"");
	if (result)
		printf("%s", result);
	else
		printf("NULL");
	printf("\", strdup(\"\") = \"");
	if (expected)
		printf("%s", expected);
	else
		printf("NULL");
	printf("\" ");
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
	free(result);
	free(expected);
}

static void	test_strdup_2(void)
{
	const char	*src;
	char		*result;
	char		*expected;

	src = "Hello";
	result = ft_strdup(src);
	expected = strdup(src);
	printf("Test 2 (simple): ft_strdup(\"Hello\") = \"");
	if (result)
		printf("%s", result);
	else
		printf("NULL");
	printf("\", ");
	printf("strdup(\"Hello\") = \"");
	if (expected)
		printf("%s", expected);
	else
		printf("NULL");
	printf("\" ");
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
	free(result);
	free(expected);
}

static void	test_strdup_3(void)
{
	const char	*src;
	char		*result;
	char		*expected;

	src = "This is a very long string to test strdup function";
	result = ft_strdup(src);
	expected = strdup(src);
	printf("Test 3 (long): content match ");
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
	free(result);
	free(expected);
}

static void	test_strdup_4(void)
{
	const char	*src;
	char		*result;
	char		*expected;

	src = "Hello\tWorld\n42!@#$%";
	result = ft_strdup(src);
	expected = strdup(src);
	printf("Test 4 (special): content match ");
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
	free(result);
	free(expected);
}

void	test_strdup(void)
{
	printf("\n=== TEST FT_STRDUP ===\n");
	test_strdup_1();
	test_strdup_2();
	test_strdup_3();
	test_strdup_4();
}
