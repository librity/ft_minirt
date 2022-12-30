/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:35:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 10:05:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix matrix;
t_matrix neo;
t_matrix trinity;
t_matrix expected;
t_t3d result_t3d;
t_t3d expected_t3d;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(matrix_4_by_4_tst)
{
	mx_set(&matrix, (t_mx_set){
						1, 2, 3, 4,
						5.5, 6.5, 7.5, 8.5,
						9, 10, 11, 12,
						13.5, 14.5, 15.5, 16.5});

	mu_assert_double_eq(1, matrix[0][0]);
	mu_assert_double_eq(4, matrix[0][3]);
	mu_assert_double_eq(5.5, matrix[1][0]);
	mu_assert_double_eq(7.5, matrix[1][2]);
	mu_assert_double_eq(11, matrix[2][2]);
	mu_assert_double_eq(13.5, matrix[3][0]);
	mu_assert_double_eq(15.5, matrix[3][2]);
}

MU_TEST(matrix_2_by_2_tst)
{
	mx_set(&matrix, (t_mx_set){
						-3, 5, 0, 0,
						1, -2, 0, 0,
						0, 0, 0, 0,
						0, 0, 0, 0});

	mu_assert_double_eq(-3, matrix[0][0]);
	mu_assert_double_eq(5, matrix[0][1]);
	mu_assert_double_eq(1, matrix[1][0]);
	mu_assert_double_eq(-2, matrix[1][1]);
}

MU_TEST(matrix_3_by_3_tst)
{
	mx_set(&matrix, (t_mx_set){
						-3, 5, 0, 0,
						1, -2, -7, 0,
						0, 1, 1, 0,
						0, 0, 0, 0});

	mu_assert_double_eq(-3, matrix[0][0]);
	mu_assert_double_eq(5, matrix[0][1]);
	mu_assert_double_eq(0, matrix[0][2]);
	mu_assert_double_eq(1, matrix[1][0]);
	mu_assert_double_eq(-2, matrix[1][1]);
	mu_assert_double_eq(-7, matrix[1][2]);
	mu_assert_double_eq(0, matrix[2][0]);
	mu_assert_double_eq(1, matrix[2][1]);
	mu_assert_double_eq(1, matrix[2][2]);
}

MU_TEST(are_equal_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 8, 7, 6,
			5, 4, 3, 2});

	mx_set(
		&trinity,
		(t_mx_set){
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 8, 7, 6,
			5, 4, 3, 2});

	mu_check(mxs_are_equal(neo, trinity));
}

MU_TEST(are_different_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 8, 7, 6,
			5, 4, 3, 2});
	mx_set(
		&trinity,
		(t_mx_set){
			2, 3, 4, 5,
			6, 7, 8, 9,
			8, 7, 6, 5,
			4, 3, 2, 1});

	mu_check(!mxs_are_equal(neo, trinity));
}

MU_TEST(mxs_multiply_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 8, 7, 6,
			5, 4, 3, 2});

	mx_set(
		&trinity,
		(t_mx_set){
			-2, 1, 2, 3,
			3, 2, 1, -1,
			4, 3, 6, 5,
			1, 2, 7, 8});

	mx_set(&expected,
			(t_mx_set){
				20, 22, 50, 48,
				44, 54, 114, 108,
				40, 58, 110, 102,
				16, 26, 46, 42});

	mxs_multiply(neo, trinity, &matrix);
	mu_check(mxs_are_equal(expected, matrix));
}

MU_TEST(mx_tuple_multiply_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			1, 2, 3, 4,
			2, 4, 4, 2,
			8, 6, 4, 1,
			0, 0, 0, 1});
	result_t3d = mx_tuple_multiply(neo, tuple(1, 2, 3, 1));
	expected_t3d = tuple(18, 24, 33, 1);

	assert_tuple_eq(expected_t3d, result_t3d);
}

MU_TEST_SUITE(matrices_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(matrix_4_by_4_tst);
	MU_RUN_TEST(matrix_2_by_2_tst);
	MU_RUN_TEST(matrix_3_by_3_tst);

	MU_RUN_TEST(are_equal_tst);
	MU_RUN_TEST(are_different_tst);

	MU_RUN_TEST(mxs_multiply_tst);
	MU_RUN_TEST(mx_tuple_multiply_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(matrices_suite);

	MU_REPORT();
	return (MU_EXIT_CODE);
}
