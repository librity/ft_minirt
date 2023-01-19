/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:23:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 20:57:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_c3d		pixel_color;
t_rgb		pixel_rgb;
t_matrix	mx_1;

void test_setup(void)
{
	initialize_mlx();
}
void test_teardown(void)
{
	destroy_camera();
	destroy_mlx();
}

MU_TEST(render_default_world_tst)
{
	set_default_world();
	set_challenge_camera(11, 11, MY_PI / 2.0);
	view_transformation(point(0, 0, -5), point(0, 0, 0), vector(0, 1, 0), &mx_1);
	set_camera_transform(mx_1);
	render();

	// pixel_rgb = c3d_to_rgb(color(0.38066, 0.47583, 0.2855));
	// printf("%d %d %d \n", pixel_rgb.red, pixel_rgb.green, pixel_rgb.blue);
	pixel_rgb = mlx_image_get_pixel_rgb(camera_buffer(), 5, 5);
	mu_assert_int_eq(97, pixel_rgb.red);
	mu_assert_int_eq(121, pixel_rgb.green);
	mu_assert_int_eq(72, pixel_rgb.blue);

}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(render_default_world_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
