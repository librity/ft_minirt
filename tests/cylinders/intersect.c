/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:23:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/28 17:58:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_cylinder;
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

MU_TEST_SUITE(intersect_cylinder_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(misses_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(intersect_cylinder_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
