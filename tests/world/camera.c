/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:23:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 20:34:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix mx_1;
t_matrix mx_2;
t_matrix mx_3;
t_matrix mx_4;
t_matrix mx_result;
t_matrix mx_expected;
t_p3d		_from;
t_p3d		_to;
t_v3d		_up;
t_camera	_camera;
t_ray		_ray;

void test_setup(void)
{
	initialize_mlx();
}
void test_teardown(void)
{
	destroy_camera();
	destroy_mlx();
}

MU_TEST(transf_default_orientation_tst)
{
	_from = point(0, 0, 0);
	_to = point(0, 0, -1);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	mx_set_identity(&mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_positive_z_tst)
{
	_from = point(0, 0, 0);
	_to = point(0, 0, 1);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	scaling(vector(-1, 1, -1), &mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_moves_world_tst)
{
	_from = point(0, 0, 8);
	_to = point(0, 0, 0);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	translation(vector(0, 0, -8), &mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_arbitrary_tst)
{
	_from = point(1.0, 3.0, 2.0);
	_to = point(4.0, -2.0, 8.0);
	_up = vector(1.0, 1.0, 0.0);
	view_transformation(_from, _to, _up, &mx_result);
	mx_set(&mx_expected, (t_mx_set){
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0.00000, 0.00000, 0.00000, 1.00000
	});

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(set_challenge_camera_tst)
{
	mx_set_identity(&mx_expected);
	set_challenge_camera(160, 120, MY_PI/2.0);

	_camera = camera();
	mu_assert_int_eq(160, _camera.width);
	mu_assert_int_eq(120, _camera.height);
	mu_assert_double_eq(MY_PI/2.0, _camera.fov_rad);
	mu_check(mxs_are_equal(mx_expected, _camera.transform));
}

MU_TEST(pixel_size_horz_tst)
{
	set_challenge_camera(200, 125, MY_PI/2.0);
	_camera = camera();

	mu_assert_double_eq(0.01, _camera.pixel_size);
}

MU_TEST(pixel_size_vert_tst)
{
	set_challenge_camera(125, 200, MY_PI/2.0);
	_camera = camera();

	mu_assert_double_eq(0.01, _camera.pixel_size);
}

// Scenario: Constructing a ray through the center of the canvas
//  Given c ← camera(201, 101, π/2)
//  When r ← ray_for_pixel(c, 100, 50)
//  Then r.origin = point(0, 0, 0)
//  And r.direction = vector(0, 0, -1)
MU_TEST(ray_for_pixel_center_tst)
{
	set_challenge_camera(201, 101, MY_PI/2.0);
	_ray = ray_for_pixel(100, 50);

	assert_tuple_eq(point(0, 0, 0), _ray.origin);
	assert_tuple_eq(vector(0, 0, -1), _ray.direction);
}

// Scenario: Constructing a ray through a corner of the canvas
//  Given c ← camera(201, 101, π/2)
//  When r ← ray_for_pixel(c, 0, 0)
//  Then r.origin = point(0, 0, 0)
//  And r.direction = vector(0.66519, 0.33259, -0.66851)
MU_TEST(ray_for_pixel_corner_tst)
{
	set_challenge_camera(201, 101, MY_PI/2.0);
	_ray = ray_for_pixel(0, 0);

	assert_tuple_eq(point(0, 0, 0), _ray.origin);
	assert_tuple_eq(vector(0.66519, 0.33259, -0.66851), _ray.direction);
}

// Scenario: Constructing a ray when the camera is transformed
//  Given c ← camera(201, 101, π/2)
//  When c.transform ← rotation_y(π/4) * translation(0, -2, 5)
//  And r ← ray_for_pixel(c, 100, 50)
//  Then r.origin = point(0, 2, -5)
//  And r.direction = vector(√2/2, 0, -√2/2)
MU_TEST(ray_for_pixel_transform_tst)
{
	set_challenge_camera(201, 101, MY_PI/2.0);
	rotation_y(MY_PI/4.0, &mx_1);
	translation(vector(0, -2, 5), &mx_2);
	mxs_multiply(mx_1, mx_2, &mx_3);
	set_camera_transform(mx_3);
	_ray = ray_for_pixel(100, 50);

	assert_tuple_eq(point(0, 2, -5), _ray.origin);
	assert_tuple_eq(vector(sqrt(2)/2, 0, -sqrt(2)/2), _ray.direction);
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(transf_default_orientation_tst);
	MU_RUN_TEST(transf_positive_z_tst);
	MU_RUN_TEST(transf_moves_world_tst);
	MU_RUN_TEST(transf_arbitrary_tst);

	MU_RUN_TEST(set_challenge_camera_tst);
	MU_RUN_TEST(pixel_size_horz_tst);
	MU_RUN_TEST(pixel_size_vert_tst);

	MU_RUN_TEST(ray_for_pixel_center_tst);
	MU_RUN_TEST(ray_for_pixel_corner_tst);
	MU_RUN_TEST(ray_for_pixel_transform_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
