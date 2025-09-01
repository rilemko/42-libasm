/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:35:00 by mconreau          #+#    #+#             */
/*   Updated: 2025/09/01 23:18:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static void	test_read_1(void)
{
	char	buf[100];
	ssize_t	result;
	ssize_t	expected;
	int		errno_ft;
	int		errno_ref;

	errno = 0;
	result = ft_read(-1, buf, 10);
	errno_ft = errno;
	errno = 0;
	expected = read(-1, buf, 10);
	errno_ref = errno;
	printf("Test 1 (bad fd): ft_read return: %zd, read return: %zd ",
		result, expected);
	printf("errno: %d vs %d ", errno_ft, errno_ref);
	if (errno_ft == errno_ref && result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

static void	test_read_2(void)
{
	char	buf[100];
	ssize_t	result;
	ssize_t	expected;
	int		errno_ft;
	int		errno_ref;

	errno = 0;
	result = ft_read(0, buf, 0);
	errno_ft = errno;
	errno = 0;
	expected = read(0, buf, 0);
	errno_ref = errno;
	printf("Test 2 (count 0): ft_read return: %zd, read return: %zd ",
		result, expected);
	printf("errno: %d vs %d ", errno_ft, errno_ref);
	if (errno_ft == errno_ref && result == expected)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	test_read(void)
{
	printf("\n=== TEST FT_READ ===\n");
	test_read_1();
	test_read_2();
}
