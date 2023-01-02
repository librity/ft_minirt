/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:36:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 18:41:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d result;
t_t3d expected;

t_matrix matrix;
t_matrix mx_translation;
t_matrix _mx_inverse;
t_matrix mx_scaling;
t_matrix mx_rotation;
t_matrix chained;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(translation_tst)
{
	translation(vector(5, -3, 2), &mx_translation);
	result = mx_tuple_multiply(mx_translation, point(-3, 4, 5));
	expected = point(2, 1, 7);

	assert_tuple_eq(expected, result);
}

MU_TEST(inverse_translation_tst)
{
	translation(vector(5, -3, 2), &mx_translation);
	mx_inverse(mx_translation, 4, &_mx_inverse);
	result = mx_tuple_multiply(_mx_inverse, point(-3, 4, 5));
	expected = point(-8, 7, 3);

	assert_tuple_eq(expected, result);
}

MU_TEST(vector_translation_tst)
{
	translation(vector(5, -3, 2), &mx_translation);
	result = mx_tuple_multiply(_mx_inverse, vector(-3, 4, 5));
	expected = vector(-3, 4, 5);

	assert_tuple_eq(expected, result);
}

MU_TEST(scaling_tst)
{
	scaling(vector(2, 3, 4), &mx_translation);
	result = mx_tuple_multiply(mx_translation, point(-4, 6, 8));
	expected = point(-8, 18, 32);

	assert_tuple_eq(expected, result);
}

MU_TEST(vector_scaling_tst)
{
	scaling(vector(2, 3, 4), &mx_translation);
	result = mx_tuple_multiply(mx_translation, vector(-4, 6, 8));
	expected = vector(-8, 18, 32);

	assert_tuple_eq(expected, result);
}

MU_TEST(inverse_scaling_tst)
{
	scaling(vector(2, 3, 4), &mx_translation);
	mx_inverse(mx_translation, 4, &_mx_inverse);
	result = mx_tuple_multiply(_mx_inverse, vector(-4, 6, 8));
	expected = vector(-2, 2, 2);

	assert_tuple_eq(expected, result);
}

MU_TEST(reflection_tst)
{
	scaling(vector(-1, 1, 1), &mx_translation);
	result = mx_tuple_multiply(mx_translation, point(2, 3, 4));
	expected = point(-2, 3, 4);

	assert_tuple_eq(expected, result);
}

MU_TEST(rotation_x_tst)
{
	rotation_x(MY_PI / 4, &mx_rotation );
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(0, sqrt(2)/2, sqrt(2)/2 );
	assert_tuple_eq(expected, result);

	rotation_x(MY_PI / 2, &mx_rotation);
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(0, 0, 1);
	assert_tuple_eq(expected, result);
}

MU_TEST(inverse_rotation_x_tst)
{
	rotation_x(MY_PI / 4, &matrix);
	mx_inverse(matrix, 4, &mx_rotation);

	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(0, sqrt(2)/2, -sqrt(2)/2 );
	assert_tuple_eq(expected, result);
}

MU_TEST(rotation_y_tst)
{
	rotation_y(MY_PI / 4, &mx_rotation );
	result = mx_tuple_multiply(mx_rotation, point(0, 0, 1));
	expected = point(sqrt(2)/2, 0, sqrt(2)/2 );
	assert_tuple_eq(expected, result);

	rotation_y(MY_PI / 2, &mx_rotation);
	result = mx_tuple_multiply(mx_rotation, point(0, 0, 1));
	expected = point(1, 0, 0);
	assert_tuple_eq(expected, result);
}

MU_TEST(rotation_z_tst)
{
	rotation_z(MY_PI / 4, &mx_rotation );
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(-sqrt(2)/2, sqrt(2)/2, 0 );
	assert_tuple_eq(expected, result);

	rotation_z(MY_PI / 2, &mx_rotation);
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(-1, 0, 0);
	assert_tuple_eq(expected, result);
}

MU_TEST(shearing_tst)
{
	shearing((t_shearing){1, 0, 0, 0, 0, 0}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(5, 3, 4);
	assert_tuple_eq(expected, result);

	shearing((t_shearing){0, 1, 0, 0, 0, 0}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(6, 3, 4);
	assert_tuple_eq(expected, result);

	shearing((t_shearing){0, 0, 1, 0, 0, 0}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(2, 5, 4);
	assert_tuple_eq(expected, result);

	shearing((t_shearing){0, 0, 0, 1, 0, 0}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(2, 7, 4);
	assert_tuple_eq(expected, result);

	shearing((t_shearing){0, 0, 0, 0, 1, 0}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(2, 3, 6);
	assert_tuple_eq(expected, result);

	shearing((t_shearing){0, 0, 0, 0, 0, 1}, &matrix);
	result = mx_tuple_multiply(matrix, point(2, 3, 4));
	expected = point(2, 3, 7);
	assert_tuple_eq(expected, result);
}

MU_TEST(individual_transformations_tst)
{
	rotation_x(MY_PI / 2, &mx_rotation);
	scaling(vector(5, 5, 5), &mx_scaling);
	translation(vector(10, 5, 7), &mx_translation);

	result = mx_tuple_multiply(mx_rotation, point(1, 0, 1));
	expected = point(1, -1, 0);
	assert_tuple_eq(expected, result);

	result = mx_tuple_multiply(mx_scaling, result);
	expected = point(5, -5, 0);
	assert_tuple_eq(expected, result);

	result = mx_tuple_multiply(mx_translation, result);
	expected = point(15, 0, 7);
	assert_tuple_eq(expected, result);
}

MU_TEST(chained_transformations_tst)
{
	rotation_x(MY_PI / 2, &mx_rotation);
	scaling(vector(5, 5, 5), &mx_scaling);
	translation(vector(10, 5, 7), &mx_translation);

	mxs_multiply(mx_translation, mx_scaling, matrix);
	mxs_multiply(matrix, mx_rotation, chained);

	result = mx_tuple_multiply(chained, point(1, 0, 1));
	expected = point(15, 0, 7);
	assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(translations_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(translation_tst);
	MU_RUN_TEST(inverse_translation_tst);
	MU_RUN_TEST(vector_translation_tst);

	MU_RUN_TEST(scaling_tst);
	MU_RUN_TEST(vector_scaling_tst);
	MU_RUN_TEST(inverse_scaling_tst);
	MU_RUN_TEST(reflection_tst);

	MU_RUN_TEST(rotation_x_tst);
	MU_RUN_TEST(inverse_rotation_x_tst);
	MU_RUN_TEST(rotation_y_tst);
	MU_RUN_TEST(rotation_z_tst);

	MU_RUN_TEST(shearing_tst);

	MU_RUN_TEST(individual_transformations_tst);
	MU_RUN_TEST(chained_transformations_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(translations_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
