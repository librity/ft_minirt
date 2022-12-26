/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 16:22:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d expected;
t_t3d result;

void assert_tuple_equals(t_t3d _expected, t_t3d _result)
{
	mu_assert_double_eq(_expected.x, _result.x);
	mu_assert_double_eq(_expected.y, _result.y);
	mu_assert_double_eq(_expected.z, _result.z);
	mu_assert_int_eq(_expected.type, _result.type);
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
	assert_tuple_equals(expected, result);

	result = tuple(4.3, -4.2, 3.1, POINT_TYPE);
	expected = (t_t3d){4.3, -4.2, 3.1, POINT_TYPE};
	assert_tuple_equals(expected, result);
}

MU_TEST(vector_tst)
{
	result = vector(43.0, -341.94, 11.421);
	expected = (t_v3d){43.0, -341.94, 11.421, VECTOR_TYPE};

	assert_tuple_equals(expected, result);
}

MU_TEST(point_tst)
{
	result = point(43.0, -341.94, 11.421);
	expected = (t_p3d){43.0, -341.94, 11.421, POINT_TYPE};

	assert_tuple_equals(expected, result);
}

MU_TEST(add_tst)
{
	result = add(
		point(3, -2, 5),
		vector(-2, 3, 1));
	expected = point(1, 1, 6);

	assert_tuple_equals(expected, result);

	// result = add(
	// 	vector(1.0, 2.0, 3.0),
	// 	vector(2.0, 3.0, 1.0)
	// );
	// expected = vector(3.0, 5.0, 4.0);

	// assert_tuple_equals(expected, result);
}

MU_TEST(sub_tst)
{
	result = sub(
		vector(1.0, 2.0, 3.0),
		vector(2.0, 3.0, 1.0));
	expected = vector(-1.0, -1.0, 2.0);

	assert_tuple_equals(expected, result);
}

MU_TEST_SUITE(vectors_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tuple_tst);
	MU_RUN_TEST(vector_tst);
	MU_RUN_TEST(point_tst);
	MU_RUN_TEST(add_tst);
	// MU_RUN_TEST(sub_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(vectors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
