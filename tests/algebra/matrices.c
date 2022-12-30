/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:35:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 15:06:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix matrix;
t_matrix neo;
t_matrix trinity;
t_matrix result;
t_matrix expected;
t_t3d result_t3d;
t_t3d expected_t3d;
t_matrix identity;
double	determinant;
double	_cofactor;
double	cofactor_a;
double	cofactor_b;

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
			0 , 9 , 3 , 0 ,
			9 , 8 , 0 , 8 ,
			1 , 8 , 5 , 3 ,
			0 , 0 , 5 , 8 });
	mx_transpose(neo, &result);

	mx_set(&expected, (t_mx_set){
		0 , 9 , 1 , 0 ,
		9 , 8 , 8 , 0 ,
		3 , 0 , 5 , 5 ,
		0 , 8 , 3 , 8});

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
			1 , 5 , 0 , 0 ,
			-3 , 2 , 0 , 0 ,
			0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 });
	determinant = mx_2by2_determinant(neo);

	mu_assert_double_eq(17, determinant);
}

MU_TEST(mx_3by3_submatrix_tst)
{
	mx_set(&neo, (t_mx_set){
		 1 , 5,  0 , 0,
		-3 , 2,  7 , 0,
		 0 , 6, -3 , 0,
		 0 , 0,  0 , 0});
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
		-6 , 1 , 1 , 6 ,
		-8 , 5 , 8 , 6 ,
		-1 , 0 , 8 , 2 ,
		-7 , 1 , -1 , 1});
	mx_submatrix(neo, 2, 1, &result);

	mx_set(&expected, (t_mx_set){
		-6 , 1 , 6 , 0,
		-8 , 8 , 6 , 0,
		-7 , -1 , 1 , 0,
		0, 0, 0, 0});
	mu_check(mxs_are_equal(expected, result));
}

MU_TEST(mx_3by3_minor_tst)
{
	mx_set(&neo, (t_mx_set){
		3 , 5 , 0 , 0,
		2 , -1 , -7 , 0,
		6 , -1 , 5 , 0,
		0, 0, 0, 0});
	determinant = mx_2by2_minor(neo, 1, 0);

	mu_assert_double_eq(25, determinant);
}

MU_TEST(cofactor_3by3_tst)
{
	mx_set(&neo, (t_mx_set){
		3 , 5 , 0 , 0,
		2 , -1 , -7 , 0,
		6 , -1 , 5 , 0,
		0, 0, 0, 0});
	cofactor_a = mx_2by2_cofactor(neo, 0, 0);
	cofactor_b = mx_2by2_cofactor(neo, 1, 0);

	mu_assert_double_eq(-12, cofactor_a);
	mu_assert_double_eq(-25, cofactor_b);
}

MU_TEST(mx_3by3_determinant_tst)
{
	mx_set(&neo, (t_mx_set){
		1 , 2 , 6 , 0,
		-5 , 8 , -4 , 0,
		2 , 6 , 4 , 0,
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
		-2 , -8 , 3 , 5,
		-3 , 1 , 7 , 3,
		1 , 2 , -9 , 6,
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
			6 , 4 , 4 , 4 ,
			5 , 5 , 7 , 6 ,
			4 , -9 , 3 , -7 ,
			9 , 1 , 7 , -6});
	determinant = mx_determinant(neo, 4);

	mu_assert_double_eq(-2120, determinant);
	mu_check(mx_is_invertible(neo, 4));

	mx_set(
		&neo,
		(t_mx_set){
			-4 , 2 , -2 , -3 ,
			9 , 6 , 2 , 6 ,
			0 , -5 , 1 , -5 ,
			0 , 0 , 0 , 0});
	determinant = mx_determinant(neo, 4);

	mu_assert_double_eq(0, determinant);
	mu_check(!mx_is_invertible(neo, 4));
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
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(matrices_suite);

	MU_REPORT();
	return (MU_EXIT_CODE);
}
