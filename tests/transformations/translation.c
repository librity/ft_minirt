/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:36:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 17:28:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d result;
t_t3d expected;
t_matrix mx_translation;
t_matrix _mx_inverse;
t_matrix mx_rotation;

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


// Scenario: Rotating a point around the x axis
//  Given p ← point(0, 1, 0)
//  And half_quarter ← rotation_x(π / 4)
//  And full_quarter ← rotation_x(π / 2)
//  Then half_quarter * p = point(0, √2/2, √2/2)
//  And full_quarter * p = point(0, 0, 1)

MU_TEST(rotation_x_tst)
{
	rotation_x(M_PI / 4, &mx_rotation );
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(0, sqrt(2)/2, sqrt(2)/2 );

	assert_tuple_eq(expected, result);

	rotation_x(M_PI / 2, &mx_rotation);
	result = mx_tuple_multiply(mx_rotation, point(0, 1, 0));
	expected = point(0, 0, 1);

	assert_tuple_eq(expected, result);
}

// Scenario: The inverse of an x-rotation rotates in the opposite direction
//  Given p ← point(0, 1, 0)
//  And half_quarter ← rotation_x(π / 4)
//  And inv ← inverse(half_quarter)
// Then inv * p = point(0, √2/2, -√2/2)

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
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(translations_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
