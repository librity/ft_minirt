              /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 13:37:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_v3d	expected;
t_v3d	result;

void	assert_v3d_equals(t_v3d	_expected, t_v3d	_result)
{
	mu_assert_double_eq(_expected.x, _result.x);
	mu_assert_double_eq(_expected.y, _result.y);
	mu_assert_double_eq(_expected.z, _result.z);
}

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(add_tst)
{
	result  = add(
		(t_v3d){1.0, 2.0, 3.0},
		(t_v3d){2.0, 3.0, 1.0}
	);
	expected = (t_v3d){3.0, 5.0, 4.0};

	assert_v3d_equals(expected, result);
}

MU_TEST(sub_tst)
{
	result = sub(
		(t_v3d){1.0, 2.0, 3.0},
		(t_v3d){2.0, 3.0, 1.0}
	);
	expected = (t_v3d){-1.0, -1.0, 2.0};

	assert_v3d_equals(expected, result);
}

MU_TEST(vec_tst)
{
	result = vector(4.0, -3.9, 1.0);
	expected = (t_v3d){4.0, -3.9, 1.0};

	assert_v3d_equals(expected, result);
}

MU_TEST(point_tst)
{
	result = point(43.0, -341.94, 11.421);
	expected = (t_v3d){43.0, -341.94, 11.421};

	assert_v3d_equals(expected, result);
}

MU_TEST_SUITE(vectors_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(add_tst);
	MU_RUN_TEST(sub_tst);
	MU_RUN_TEST(vec_tst);
	MU_RUN_TEST(point_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(vectors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
