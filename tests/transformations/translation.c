/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:36:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 16:51:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int foo;
t_t3d result;
t_t3d expected;
t_matrix mx_translation;
t_matrix _mx_inverse;

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

MU_TEST_SUITE(translations_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(translation_tst);
	MU_RUN_TEST(inverse_translation_tst);
	MU_RUN_TEST(vector_translation_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(translations_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
