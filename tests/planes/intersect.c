/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:12:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:46:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../tests.h"

t_object	*_plane;
t_ray		_ray;
t_intxs		xs;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_ray_lalloc();
	free_world_lalloc();
}

MU_TEST(intersect_parallel_tst)
{
	_plane = plane();
	_ray = ray(point(0, 10, 0), vector(0, 0, 1));
	xs = intersect_object(_plane, _ray);

	mu_check(xs.list == NULL);
	mu_assert_int_eq(0, xs.count);
}

MU_TEST(intersect_coplanar_tst)
{
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	xs = intersect_object(_plane, _ray);

	mu_check(xs.list == NULL);
	mu_assert_int_eq(0, xs.count);
}

MU_TEST_SUITE(plane_intersect_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(intersect_parallel_tst);
	MU_RUN_TEST(intersect_coplanar_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plane_intersect_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
