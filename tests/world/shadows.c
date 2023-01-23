/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:23:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/23 18:52:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_c3d		pixel_color;
t_rgb		pixel_rgb;
t_matrix	mx_1;

void test_setup(void)
{
	c()->objects = NULL;
}
void test_teardown(void)
{
	free_world_lalloc();
	free_ray_lalloc();
	c()->objects = NULL;
}

MU_TEST(is_shadowed_collinear_tst)
{
	set_default_world();

	mu_check(is_shadowed(point(0.0, 10.0, 0.0)) == false);
}

MU_TEST(is_shadowed_between_tst)
{
	set_default_world();

	mu_check(is_shadowed(point(10, -10, 10)) == true);
}

MU_TEST(is_shadowed_behind_light_tst)
{
	set_default_world();

	mu_check(is_shadowed(point(-20, 20, -20)) == false);
}

MU_TEST(is_shadowed_behind_point_tst)
{
	set_default_world();

	mu_check(is_shadowed(point(-2, 2, -2)) == false);
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(is_shadowed_collinear_tst);
	MU_RUN_TEST(is_shadowed_between_tst);
	MU_RUN_TEST(is_shadowed_behind_light_tst);
	MU_RUN_TEST(is_shadowed_behind_point_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
