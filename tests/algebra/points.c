/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 16:10:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_t3d expected;
t_t3d result;
t_t3d _tuple;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(point_tst)
{
	result = point(43.0, -341.94, 11.421);
	expected = (t_p3d){43.0, -341.94, 11.421, POINT_TYPE};

	assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(vectors_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(point_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(vectors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
