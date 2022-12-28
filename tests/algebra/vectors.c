/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 16:24:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d expected;
t_t3d result;
t_t3d _tuple;
double	result_d;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(vector_tst)
{
	result = vector(43.0, -341.94, 11.421);
	expected = (t_v3d){43.0, -341.94, 11.421, VECTOR_TYPE};

	assert_tuple_eq(expected, result);
}

MU_TEST(magnitude_tst)
{
	_tuple = vector(1, 0, 0);
	mu_assert_double_eq(1, magnitude(_tuple));

	_tuple = vector(0, 1, 0);
	mu_assert_double_eq(1, magnitude(_tuple));

	_tuple = vector(0, 0, 1);
	mu_assert_double_eq(1, magnitude(_tuple));

	_tuple = vector(1, 2, 3);
	mu_assert_double_eq(sqrt(14), magnitude(_tuple));

	_tuple = vector(-1, -2, -3);
	mu_assert_double_eq(sqrt(14), magnitude(_tuple));
}

MU_TEST(normalize_tst)
{
	result = normalize(vector(4, 0, 0));
	expected = vector(1, 0, 0);
	assert_tuple_eq(expected, result);

	result = normalize(vector(1, 2, 3));
	expected = vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14));
	assert_tuple_eq(expected, result);

	result_d = magnitude(normalize(vector(1, 2, 3)));
	mu_assert_double_eq(1, result_d);
}

MU_TEST_SUITE(vectors_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(vector_tst);

	MU_RUN_TEST(magnitude_tst);
	MU_RUN_TEST(normalize_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(vectors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
