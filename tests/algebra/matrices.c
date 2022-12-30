/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:35:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 15:47:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix neo;
t_matrix trinity;
t_matrix morpheus;

t_matrix matrix;
t_matrix result;
t_matrix expected;
t_t3d result_t3d;
t_t3d expected_t3d;
t_matrix identity;
double determinant;
double _cofactor;
double cofactor_a;
double cofactor_b;

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

MU_TEST(mx_identity_multiply_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			0, 1, 2, 4,
			1, 2, 4, 8,
			2, 4, 8, 16,
			4, 8, 16, 32});
	mx_set_identity(&identity);
	mxs_multiply(identity, neo, &matrix);
	mu_check(mxs_are_equal(neo, matrix));
}

MU_TEST(mx_transpose_tst)
{
	mx_set(&neo, (t_mx_set){
					 0, 9, 3, 0,
					 9, 8, 0, 8,
					 1, 8, 5, 3,
					 0, 0, 5, 8});
	mx_transpose(neo, &result);

	mx_set(&expected, (t_mx_set){
						  0, 9, 1, 0,
						  9, 8, 8, 0,
						  3, 0, 5, 5,
						  0, 8, 3, 8});

	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(mx_transpose_identity_tst)
{
	mx_set_identity(&identity);
	mx_transpose(identity, &result);

	mx_set(&expected, (t_mx_set){
						  1, 0, 0, 0,
						  0, 1, 0, 0,
						  0, 0, 1, 0,
						  0, 0, 0, 1});
	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(mx_2by2_determinant_tst)
{
	mx_set(&neo, (t_mx_set){
					 1, 5, 0, 0,
					 -3, 2, 0, 0,
					 0, 0, 0, 0,
					 0, 0, 0, 0});
	determinant = mx_2by2_determinant(neo);

	mu_assert_double_eq(17, determinant);
}

MU_TEST(mx_3by3_submatrix_tst)
{
	mx_set(&neo, (t_mx_set){
					 1, 5, 0, 0,
					 -3, 2, 7, 0,
					 0, 6, -3, 0,
					 0, 0, 0, 0});
	mx_submatrix(neo, 0, 2, &result);

	mx_set(&expected, (t_mx_set){
						  -3, 2, 0, 0,
						  0, 6, 0, 0,
						  0, 0, 0, 0,
						  0, 0, 0, 0});
	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(mx_4by4_submatrix_tst)
{
	mx_set(&neo, (t_mx_set){
					 -6, 1, 1, 6,
					 -8, 5, 8, 6,
					 -1, 0, 8, 2,
					 -7, 1, -1, 1});
	mx_submatrix(neo, 2, 1, &result);

	mx_set(&expected, (t_mx_set){
						  -6, 1, 6, 0,
						  -8, 8, 6, 0,
						  -7, -1, 1, 0,
						  0, 0, 0, 0});
	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(mx_3by3_minor_tst)
{
	mx_set(&neo, (t_mx_set){
					 3, 5, 0, 0,
					 2, -1, -7, 0,
					 6, -1, 5, 0,
					 0, 0, 0, 0});
	determinant = mx_2by2_minor(neo, 1, 0);

	mu_assert_double_eq(25, determinant);
}

MU_TEST(cofactor_3by3_tst)
{
	mx_set(&neo, (t_mx_set){
					 3, 5, 0, 0,
					 2, -1, -7, 0,
					 6, -1, 5, 0,
					 0, 0, 0, 0});
	cofactor_a = mx_2by2_cofactor(neo, 0, 0);
	cofactor_b = mx_2by2_cofactor(neo, 1, 0);

	mu_assert_double_eq(-12, cofactor_a);
	mu_assert_double_eq(-25, cofactor_b);
}

MU_TEST(mx_3by3_determinant_tst)
{
	mx_set(&neo, (t_mx_set){
					 1, 2, 6, 0,
					 -5, 8, -4, 0,
					 2, 6, 4, 0,
					 0, 0, 0, 0});

	_cofactor = mx_cofactor(neo, 3, 0, 0);
	mu_assert_double_eq(56, _cofactor);

	_cofactor = mx_cofactor(neo, 3, 0, 1);
	mu_assert_double_eq(12, _cofactor);

	_cofactor = mx_cofactor(neo, 3, 0, 2);
	mu_assert_double_eq(-46, _cofactor);

	determinant = mx_determinant(neo, 3);
	mu_assert_double_eq(-196, determinant);
}

MU_TEST(mx_4by4_determinant_tst)
{
	mx_set(&neo, (t_mx_set){
					 -2, -8, 3, 5,
					 -3, 1, 7, 3,
					 1, 2, -9, 6,
					 -6, 7, 7, -9});

	_cofactor = mx_cofactor(neo, 4, 0, 0);
	mu_assert_double_eq(690, _cofactor);

	_cofactor = mx_cofactor(neo, 4, 0, 1);
	mu_assert_double_eq(447, _cofactor);

	_cofactor = mx_cofactor(neo, 4, 0, 2);
	mu_assert_double_eq(210, _cofactor);

	_cofactor = mx_cofactor(neo, 4, 0, 3);
	mu_assert_double_eq(51, _cofactor);

	determinant = mx_determinant(neo, 4);
	mu_assert_double_eq(-4071, determinant);
}

MU_TEST(is_invertible_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			6, 4, 4, 4,
			5, 5, 7, 6,
			4, -9, 3, -7,
			9, 1, 7, -6});
	determinant = mx_determinant(neo, 4);

	mu_assert_double_eq(-2120, determinant);
	mu_check(mx_is_invertible(neo, 4));

	mx_set(
		&neo,
		(t_mx_set){
			-4, 2, -2, -3,
			9, 6, 2, 6,
			0, -5, 1, -5,
			0, 0, 0, 0});
	determinant = mx_determinant(neo, 4);

	mu_assert_double_eq(0, determinant);
	mu_check(!mx_is_invertible(neo, 4));
}

MU_TEST(inverse_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			-5, 2, 6, -8,
			1, -5, 1, 8,
			7, 7, -6, -7,
			1, -3, 7, 4});
	mx_set(
		&expected,
		(t_mx_set){
			0.21805, 0.45113, 0.24060, -0.04511,
			-0.80827, -1.45677, -0.44361, 0.52068,
			-0.07895, -0.22368, -0.05263, 0.19737,
			-0.52256, -0.81391, -0.30075, 0.30639});
	mx_inverse(neo, 4, &result);

	mu_assert_double_eq(532.0, mx_determinant(neo, 4));

	mu_assert_double_eq(-160.0, mx_cofactor(neo, 4, 2, 3));
	mu_assert_double_eq(-160.0 / 532.0, result[3][2]);

	mu_assert_double_eq(105.0, mx_cofactor(neo, 4, 3, 2));
	mu_assert_double_eq(105.0 / 532.0, result[2][3]);

	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(inverse_2_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			8, -5, 9, 2,
			7, 5, 6, 1,
			-6, 0, 9, 6,
			-3, 0, -9, -4});
	mx_set(
		&expected,
		(t_mx_set){
			-0.15385, -0.15385, -0.28205, -0.53846,
			-0.07692, 0.12308, 0.02564, 0.03077,
			0.35897, 0.35897, 0.43590, 0.92308,
			-0.69231, -0.69231, -0.76923, -1.92308});
	mx_inverse(neo, 4, &result);
	mu_check(mxs_are_equal(expected, result));

	mx_set(
		&neo,
		(t_mx_set){
			9, 3, 0, 9,
			-5, -2, -6, -3,
			-4, 9, 6, 4,
			-7, 6, 6, 2});
	mx_set(
		&expected,
		(t_mx_set){
			-0.04074, -0.07778, 0.14444, -0.22222,
			-0.07778, 0.03333, 0.36667, -0.33333,
			-0.02901, -0.14630, -0.10926, 0.12963,
			0.17778, 0.06667, -0.26667, 0.33333});
	mx_inverse(neo, 4, &result);
	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(inverse_3_tst)
{
	mx_set(
		&neo,
		(t_mx_set){
			3, -9, 7, 3,
			3, -8, 2, -9,
			-4, 4, 4, 1,
			-6, 5, -1, 1});
	mx_set(
		&trinity,
		(t_mx_set){
			8, 2, 2, 2,
			3, -1, 7, 0,
			7, 0, 5, 4,
			6, -2, 0, 5});
	mxs_multiply(neo, trinity, &morpheus);
	mx_inverse(trinity, 4, &matrix);
	mxs_multiply(morpheus, matrix, &result);

	mu_check(mxs_are_equal(neo, result));
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
	MU_RUN_TEST(mx_identity_multiply_tst);

	MU_RUN_TEST(mx_transpose_tst);
	MU_RUN_TEST(mx_transpose_identity_tst);

	MU_RUN_TEST(mx_2by2_determinant_tst);
	MU_RUN_TEST(mx_3by3_determinant_tst);

	MU_RUN_TEST(mx_3by3_submatrix_tst);
	MU_RUN_TEST(mx_4by4_submatrix_tst);

	MU_RUN_TEST(mx_3by3_minor_tst);
	MU_RUN_TEST(cofactor_3by3_tst);
	MU_RUN_TEST(mx_4by4_determinant_tst);

	MU_RUN_TEST(is_invertible_tst);
	MU_RUN_TEST(inverse_tst);
	MU_RUN_TEST(inverse_2_tst);
	MU_RUN_TEST(inverse_3_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(matrices_suite);

	MU_REPORT();
	return (MU_EXIT_CODE);
}
