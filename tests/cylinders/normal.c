/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/02 18:57:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_cyl;
t_v3d		result;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_world_lalloc();
}

void	assert_normal_at(t_p3d point, t_v3d expected)
{
	_cyl = cylinder();
	result = object_normal_at(_cyl, point);

	assert_tuple_eq(expected, result);
}

MU_TEST(normal_at_tst)
{
	assert_normal_at(point(1, 0, 0), vector(1, 0, 0));
	assert_normal_at(point(0, 5, -1), vector(0, 0, -1));
	assert_normal_at(point(0, -2, 1), vector(0, 0, 1));
	assert_normal_at(point(-1, 1, 0), vector(-1, 0, 0));
}

void assert_closed_normal(t_p3d point, t_v3d expected)
{
	_cyl = cylinder();
	_cyl->minimum = 1;
	_cyl->maximum = 2;
	_cyl->closed = true;
	result = _cyl->normal_at(_cyl, point);

	assert_tuple_eq(expected, result);
}

MU_TEST(normal_cap_tst)
{
	assert_closed_normal(point(0, 1, 0), vector(0, -1, 0));
	assert_closed_normal(point(0, 1, 0), vector(0, -1, 0));
	assert_closed_normal(point(0, 1, 0.5), vector(0, -1, 0));
	assert_closed_normal(point(0, 2, 0), vector(0, 1, 0));
	assert_closed_normal(point(0.5, 2, 0), vector(0, 1, 0));
	assert_closed_normal(point(0, 2, 0.5), vector(0, 1, 0));
}

MU_TEST_SUITE(cylinder_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(normal_at_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(cylinder_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
