/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:23:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 20:11:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_cylinder;
t_ray		_ray;
t_intxs		xs;
t_intx		*inter;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_ray_lalloc();
	free_world_lalloc();
}

void	assert_miss(t_p3d origin, t_v3d direction)
{
	_cylinder = cylinder();
	direction = normalize(direction);
	_ray = ray(origin, direction);
	xs = intersect_object(_cylinder, _ray);

	mu_assert_int_eq(0, xs.count);
	mu_check(xs.list == NULL);
}

MU_TEST(misses_tst)
{
	assert_miss(point(1, 0, 0), vector(0, 1, 0));
	assert_miss(point(0, 0, 0), vector(0, 1, 0));
	assert_miss(point(0, 0, -5), vector(1, 1, 1));
}

void	assert_hit(t_p3d origin, t_v3d direction, double t0, double t1)
{
	_cylinder = cylinder();
	direction = normalize(direction);
	_ray = ray(origin, direction);
	xs = intersect_object(_cylinder, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.list->content;
	mu_check(_cylinder == inter->object);
	mu_assert_double_eq(t0, inter->t);

	inter = xs.list->next->content;
	mu_check(_cylinder == inter->object);
	mu_assert_double_eq(t1, inter->t);
}

MU_TEST(hits_tst){
	assert_hit(point(1, 0, -5), vector(0, 0, 1), 5, 5);
	assert_hit(point(0, 0, -5), vector(0, 0, 1), 4, 6);
	assert_hit(point(0.5, 0, -5), vector(0.1, 1, 1), 6.80798 , 7.08872);
}

void	assert_truncated_hit(t_p3d origin, t_v3d direction, int count)
{
	_cylinder = cylinder();
	_cylinder->minimum = 1;
	_cylinder->maximum = 2;
	direction = normalize(direction);
	_ray = ray(origin, direction);
	xs = intersect_object(_cylinder, _ray);

	mu_assert_int_eq(count, xs.count);
}

MU_TEST(truncated_hits_tst){
	assert_truncated_hit(point(0, 1.5, 0), vector(0.1, 1, 0), 0);
	assert_truncated_hit(point(0, 3, -5), vector(0, 0, 1), 0);
	assert_truncated_hit(point(0, 0, -5), vector(0, 0, 1), 0);
	assert_truncated_hit(point(0, 2, -5), vector(0, 0, 1), 0);
	assert_truncated_hit(point(0, 1, -5), vector(0, 0, 1), 0);
	assert_truncated_hit(point(0, 1.5, -2), vector(0, 0, 1), 2);
}

MU_TEST_SUITE(intersect_cylinder_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(misses_tst);
	MU_RUN_TEST(hits_tst);
	MU_RUN_TEST(truncated_hits_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(intersect_cylinder_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
