/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
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

static void	test_strcpy_1(void)
{
	char		dst[50];
	char		dst_ref[50];
	const char	*src;
	char		*result;

	src = "";
	memset(dst, 0, 50);
	memset(dst_ref, 0, 50);
	result = ft_strcpy(dst, src);
	strcpy(dst_ref, src);
	printf("Test 1 (empty): ft_strcpy result = \"%s\", strcpy result = \"%s\" ",
		dst, dst_ref);
	if (result == dst)
		printf("return: OK ");
	else
		printf("return: KO ");
	if (strcmp(dst, dst_ref) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strcpy_2(void)
{
	char		dst[50];
	char		dst_ref[50];
	const char	*src;
	char		*result;

	src = "Hello";
	memset(dst, 0, 50);
	memset(dst_ref, 0, 50);
	result = ft_strcpy(dst, src);
	strcpy(dst_ref, src);
	printf("Test 2 (simple): ft_strcpy result = \"%s\", ",
		dst);
	printf("strcpy result = \"%s\" ", dst_ref);
	if (result == dst)
		printf("return: OK ");
	else
		printf("return: KO ");
	if (strcmp(dst, dst_ref) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_strcpy_3(void)
{
	char		dst[50];
	char		dst_ref[50];
	const char	*src;
	char		*result;

	src = "Hello World 42";
	memset(dst, 0, 50);
	memset(dst_ref, 0, 50);
	result = ft_strcpy(dst, src);
	strcpy(dst_ref, src);
	printf("Test 3 (spaces): ft_strcpy result = \"%s\", ",
		dst);
	printf("strcpy result = \"%s\" ", dst_ref);
	if (result == dst)
		printf("return: OK ");
	else
		printf("return: KO ");
	if (strcmp(dst, dst_ref) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	test_strcpy(void)
{
	printf("\n=== TEST FT_STRCPY ===\n");
	test_strcpy_1();
	test_strcpy_2();
	test_strcpy_3();
}
