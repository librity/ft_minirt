/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:35:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 20:50:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix	matrix;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(matrix_tst)
{
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[0][3] = 4;

	matrix[1][0] = 5.5;
	matrix[1][1] = 6.5;
	matrix[1][2] = 7.5;
	matrix[1][3] = 8.5;

	matrix[2][0] = 9;
	matrix[2][1] = 10;
	matrix[2][2] = 11;
	matrix[2][3] = 12;

	matrix[3][0] = 13.5;
	matrix[3][1] = 14.5;
	matrix[3][2] = 15.5;
	matrix[3][3] = 16.5;

	mu_assert_double_eq(1, matrix[0][0]);
	mu_assert_double_eq(4, matrix[0][3]);
	mu_assert_double_eq(5.5, matrix[1][0]);
	mu_assert_double_eq(7.5, matrix[1][2]);
	mu_assert_double_eq(11, matrix[2][2]);
	mu_assert_double_eq(13.5, matrix[3][0]);
	mu_assert_double_eq(15.5, matrix[3][2]);
}

MU_TEST_SUITE(matrices_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(matrix_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(matrices_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
