/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:35:00 by mconreau          #+#    #+#             */
/*   Updated: 2025/09/01 23:11:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static void	test_write_1(void)
{
	size_t	result;

	printf("Test 1: ");
	result = ft_write(1, "Hello World\n", 12);
	printf("ft_write return: %zu, expected: %zu ", result, (size_t)12);
	if (result == 12)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_write_2(void)
{
	size_t	result;

	printf("Test 2: ");
	result = ft_write(1, "", 0);
	printf("ft_write(empty) return: %zu, expected: %zu ", result, (size_t)0);
	if (result == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_write_3(void)
{
	size_t	result;
	ssize_t	expected;
	int		errno_ft;
	int		errno_ref;

	errno = 0;
	result = ft_write(-1, "test", 4);
	errno_ft = errno;
	errno = 0;
	expected = write(-1, "test", 4);
	errno_ref = errno;
	printf("Test 3 (bad fd): ft_write return: %zd, write return: %zd ",
		(ssize_t)result, expected);
	printf("errno: %d vs %d ", errno_ft, errno_ref);
	if (errno_ft == errno_ref && (ssize_t)result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	test_write(void)
{
	printf("\n=== TEST FT_WRITE ===\n");
	test_write_1();
	test_write_2();
	test_write_3();
}
