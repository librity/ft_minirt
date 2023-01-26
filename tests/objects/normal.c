/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:37:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:30:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_sphere;
t_v3d		normal;
t_v3d		reflected;
t_v3d		v2;
t_matrix	mx;
t_matrix	scaling_mx;
t_matrix	z_rotation_mx;
t_matrix	mx3;
t_light		_light;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(normal_at_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;
	_sphere = sphere();

	normal = object_normal_at(_sphere, point(1, 0, 0));
	assert_tuple_eq(vector(1, 0, 0), normal);

	normal = object_normal_at(_sphere, point(0, 1, 0));
	assert_tuple_eq(vector(0, 1, 0), normal);

	normal = object_normal_at(_sphere, point(0, 0, 1));
	assert_tuple_eq(vector(0, 0, 1), normal);

	normal = object_normal_at(_sphere, point(-1, 0, 0));
	assert_tuple_eq(vector(-1, 0, 0), normal);

	normal = object_normal_at(_sphere, point(0, -1, 0));
	assert_tuple_eq(vector(0, -1, 0), normal);

	normal = object_normal_at(_sphere, point(0, 0, -1));
	assert_tuple_eq(vector(0, 0, -1), normal);

	normal = object_normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));
	assert_tuple_eq(vector(sqrt3o3, sqrt3o3, sqrt3o3), normal);
}

MU_TEST(normal_at_radius_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;
	_sphere = create_sphere(point(0, 0, 0), 42.0, rgb_red());

	normal = object_normal_at(_sphere, point(1, 0, 0));
	assert_tuple_eq(vector(1, 0, 0), normal);

	normal = object_normal_at(_sphere, point(0, 1, 0));
	assert_tuple_eq(vector(0, 1, 0), normal);

	normal = object_normal_at(_sphere, point(0, 0, 1));
	assert_tuple_eq(vector(0, 0, 1), normal);

	normal = object_normal_at(_sphere, point(-1, 0, 0));
	assert_tuple_eq(vector(-1, 0, 0), normal);

	normal = object_normal_at(_sphere, point(0, -1, 0));
	assert_tuple_eq(vector(0, -1, 0), normal);

	normal = object_normal_at(_sphere, point(0, 0, -1));
	assert_tuple_eq(vector(0, 0, -1), normal);

	normal = object_normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));
	assert_tuple_eq(vector(sqrt3o3, sqrt3o3, sqrt3o3), normal);
}

MU_TEST(normal_at_is_normalized_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;
	_sphere = sphere();
	normal = object_normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));

	assert_tuple_eq(normalize(normal), normal);
}

MU_TEST(normal_at_translation_tst)
{
	_sphere = sphere();
	translation(vector(0, 1, 0), &mx);
	set_transform(_sphere, mx);
	normal = object_normal_at(_sphere, point(0, 1.70711, -0.70711));

	assert_tuple_eq(vector(0, 0.70711, -0.70711), normal);
}

MU_TEST(normal_at_scaling_rotation_z_tst)
{
	double	sqrt2o2 = sqrt(2.0) / 2.0;
	_sphere = sphere();
	scaling(vector(1, 0.5, 1), &scaling_mx);
	rotation_z(MY_PI / 5.0, &z_rotation_mx);
	mxs_multiply(scaling_mx, z_rotation_mx, &mx);
	set_transform(_sphere, mx);
	normal = object_normal_at(_sphere, point(0, sqrt2o2, -sqrt2o2));

	assert_tuple_eq(vector(0, 0.97014, -0.24254), normal);
}

MU_TEST(reflecting_tst)
{
	reflected = reflect(vector(1, -1, 0), vector(0, 1, 0));

	assert_tuple_eq(vector(1, 1, 0), reflected);
}

MU_TEST(reflect_slanted_surface_tst)
{
	double	sqrt2o2 = sqrt(2) / 2;
	reflected = reflect(vector(0, -1, 0), vector(sqrt2o2, sqrt2o2, 0));
	assert_tuple_eq(vector(1, 0, 0), reflected);
}

MU_TEST(point_light_tst)
{
	_light = point_light(point(0, 0, 0), 0.2, color_rgb(255, 255, 255));
	assert_tuple_eq(point(0, 0, 0), _light.origin);
	assert_tuple_eq(color(1.0, 1.0, 1.0), _light.color_3d);
	assert_tuple_eq(color(0.2, 0.2, 0.2), _light.intensity);

	_light = point_light(point(-40.0,50.0,0.0), 0.6, color_rgb(10,0,255));
	assert_tuple_eq(point(-40.0,50.0,0.0), _light.origin);
	assert_tuple_eq(color(
		10.0 / 255.0 ,
		0.0 / 255.0 ,
		255.0 / 255.0
		), _light.color_3d);
	assert_tuple_eq(color(
		10.0 / 255.0 * 0.6,
		0.0 / 255.0  * 0.6,
		255.0 / 255.0 * 0.6
		), _light.intensity);
}

MU_TEST_SUITE(normal_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(normal_at_tst);
	MU_RUN_TEST(normal_at_radius_tst);
	MU_RUN_TEST(normal_at_is_normalized_tst);

	MU_RUN_TEST(normal_at_translation_tst);
	MU_RUN_TEST(normal_at_scaling_rotation_z_tst);

	MU_RUN_TEST(reflecting_tst);
	MU_RUN_TEST(reflect_slanted_surface_tst);

	MU_RUN_TEST(point_light_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(normal_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
