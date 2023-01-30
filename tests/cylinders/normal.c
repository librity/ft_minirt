/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 19:23:18 by lpaulo-m         ###   ########.fr       */
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


// Scenario Outline: Normal vector on a cylinder
//  Given cyl ← cylinder()
//  When n ← local_normal_at(cyl, <point>)
//  Then n = <normal>
void	assert_normal_at(t_p3d point, t_v3d expected)
{
	_cyl = cylinder();
	result = object_normal_at(_cyl, point);

	assert_tuple_eq(expected, result);
}

//  Examples:
//  | point | normal |
MU_TEST(normal_at_tst)
{
	assert_normal_at(point(1, 0, 0), vector(1, 0, 0));
	assert_normal_at(point(0, 5, -1), vector(0, 0, -1));
	assert_normal_at(point(0, -2, 1), vector(0, 0, 1));
	assert_normal_at(point(-1, 1, 0), vector(-1, 0, 0));
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
