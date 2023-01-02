/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:47:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 20:01:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../tests.h"

t_ray	result;
t_ray	_ray;
t_t3d	expected_t3d;
t_object	*_sphere;
t_intersect	xs;

void test_setup(void)
{
}
void test_teardown(void)
{
	free_lalloc();
}

MU_TEST(rays_tst)
{
	result = ray(point(1, 2, 3), vector(4, 5, 6));

	expected_t3d = point(1, 2, 3);
	assert_tuple_eq(expected_t3d, result.origin);

	expected_t3d = vector(4, 5, 6);
	assert_tuple_eq(expected_t3d, result.direction);
}

MU_TEST(position_tst)
{
	_ray = ray(point(2, 3, 4), vector(1, 0, 0));

	expected_t3d = position(_ray, 0);
	assert_tuple_eq(expected_t3d, point(2, 3, 4));

	expected_t3d = position(_ray, 1);
	assert_tuple_eq(expected_t3d, point(3, 3, 4));

	expected_t3d = position(_ray, -1);
	assert_tuple_eq(expected_t3d, point(1, 3, 4));

	expected_t3d = position(_ray, 2.5);
	assert_tuple_eq(expected_t3d, point(4.5, 3, 4));
}

MU_TEST(intersects_ahead_tst)
{
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	mu_assert_double_eq(4.0, xs.roots[0]);
	mu_assert_double_eq(6.0, xs.roots[1]);
}

MU_TEST(ray_misses_tst)
{
	_ray = ray(point(0, 2, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}

MU_TEST(ray_inside_tst)
{
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	mu_assert_double_eq(-1.0, xs.roots[0]);
	mu_assert_double_eq(1.0, xs.roots[1]);
}


MU_TEST(ray_behind_tst)
{
	_ray = ray(point(0, 0, 5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	mu_assert_double_eq(-6.0, xs.roots[0]);
	mu_assert_double_eq(-4.0, xs.roots[1]);
}

MU_TEST_SUITE(rays_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(rays_tst);
	MU_RUN_TEST(position_tst);

	MU_RUN_TEST(intersects_ahead_tst);
	MU_RUN_TEST(ray_inside_tst);
	MU_RUN_TEST(ray_misses_tst);
	MU_RUN_TEST(ray_behind_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(rays_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
