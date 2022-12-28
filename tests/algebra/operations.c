/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 16:03:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d expected;
t_t3d result;
t_t3d _tuple;

void assert_tuple_eq(t_t3d _expected, t_t3d _result)
{
	mu_assert_double_eq(_expected.x, _result.x);
	mu_assert_double_eq(_expected.y, _result.y);
	mu_assert_double_eq(_expected.z, _result.z);
	mu_assert_double_eq(_expected.type, _result.type);
}

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(tuple_tst)
{
	result = tuple(1.0, 2.0, 3.0, VECTOR_TYPE);
	expected = (t_t3d){1.0, 2.0, 3.0, VECTOR_TYPE};
	assert_tuple_eq(expected, result);

	result = tuple(4.3, -4.2, 3.1, POINT_TYPE);
	expected = (t_t3d){4.3, -4.2, 3.1, POINT_TYPE};
	assert_tuple_eq(expected, result);
}

MU_TEST(vector_tst)
{
	result = vector(43.0, -341.94, 11.421);
	expected = (t_v3d){43.0, -341.94, 11.421, VECTOR_TYPE};

	assert_tuple_eq(expected, result);
}

MU_TEST(point_tst)
{
	result = point(43.0, -341.94, 11.421);
	expected = (t_p3d){43.0, -341.94, 11.421, POINT_TYPE};

	assert_tuple_eq(expected, result);
}

MU_TEST(add_tst)
{
	result = add(
		point(3, -2, 5),
		vector(-2, 3, 1));
	expected = point(1, 1, 6);
	assert_tuple_eq(expected, result);

	result = add(
		vector(-2, 3, 1),
		point(3, -2, 5));
	expected = point(1, 1, 6);
	assert_tuple_eq(expected, result);

	result = add(
		vector(1.0, -5.0, 4.0),
		vector(3.0, 4.3, 2.0));
	expected = vector(4, -0.7, 6.0);
	assert_tuple_eq(expected, result);

	result = add(
		point(1.0, -5.0, 4.0),
		point(3.0, 4.3, 2.0));
	expected = null_tuple();
	assert_tuple_eq(expected, result);
}

MU_TEST(sub_tst)
{
	result = sub(
		point(3, 2, 1),
		point(5, 6, 7));
	expected = vector(-2, -4, -6);
	assert_tuple_eq(expected, result);

	result = sub(
		point(3, 2, 1),
		vector(5, 6, 7));
	expected = point(-2, -4, -6);
	assert_tuple_eq(expected, result);

	result = sub(
		vector(5, 6, 7),
		point(3, 2, 1));
	expected = null_tuple();
	assert_tuple_eq(expected, result);

	result = sub(
		vector(3, 2, 1),
		vector(5, 6, 7));
	expected = vector(-2, -4, -6);
	assert_tuple_eq(expected, result);

	result = sub(
		vector(0, 0, 0),
		vector(3, 2, 1));
	expected = vector(-3, -2, -1);
	assert_tuple_eq(expected, result);
}

MU_TEST(neg_tst)
{
	result = neg(tuple(1, -2, 3, -4));
	expected = tuple(-1, 2, -3, 4);
	assert_tuple_eq(expected, result);
}

MU_TEST(scalar_times_tst)
{
	result = scalar_times(
		3.5, tuple(1, -2, 3, -4)
	);
	expected = tuple(3.5, -7, 10.5, -14);
	assert_tuple_eq(expected, result);

	result = scalar_times(
		0.5, tuple(1, -2, 3, -4)
	);
	expected = tuple(0.5, -1, 1.5, -2);
	assert_tuple_eq(expected, result);
}

MU_TEST(scalar_div_tst)
{
	result = scalar_div(
		2, tuple(1, -2, 3, -4)
	);
	expected = tuple(0.5, -1, 1.5, -2);
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


MU_TEST_SUITE(vectors_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tuple_tst);
	MU_RUN_TEST(vector_tst);
	MU_RUN_TEST(point_tst);

	MU_RUN_TEST(add_tst);
	MU_RUN_TEST(sub_tst);
	MU_RUN_TEST(neg_tst);

	MU_RUN_TEST(scalar_times_tst);
	MU_RUN_TEST(scalar_div_tst);

	MU_RUN_TEST(magnitude_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(vectors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
