/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_v5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:40:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 19:26:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	wall_material(void)
{
	t_material	mat;

	mat = material();
	mat.color = color_3d(1, 0.9, 0.9);
	mat.specular = 0;
	return (mat);
}

void create_floor(void)
{
	t_object *_plane;
	// t_matrix mx_scal;

	_plane = plane();
	// scaling(vector(10, 0.01, 10), &mx_scal);
	// set_transform(_plane, mx_scal);
	_plane->material = wall_material();
}

// middle ← sphere()
// middle.transform ← translation(-0.5, 1, 0.5)
// middle.material ← material()
// middle.material.color ← color(0.1, 1, 0.5)
// middle.material.diffuse ← 0.7
// middle.material.specular ← 0.3
void create_middle_sphere(void)
{
	t_object *_sphere;
	t_matrix mx;

	_sphere = sphere();
	translation(vector(-0.5, 1, 0.5), &mx);
	set_transform(_sphere, mx);
	_sphere->material = material();
	_sphere->material.color = color_3d(0.1, 1, 0.5);
	_sphere->material.specular = 0.3;
	_sphere->material.diffuse = 0.7;
}

// right ← sphere()
// right.transform ← translation(1.5, 0.5, -0.5) * scaling(0.5, 0.5, 0.5)
// right.material ← material()
// right.material.color ← color(0.5, 1, 0.1)
// right.material.diffuse ← 0.7
// right.material.specular ← 0.3
void create_right_sphere(void)
{
	t_object *_sphere;
	t_matrix mx_1;
	t_matrix mx_2;
	t_matrix transform;

	_sphere = sphere();
	translation(vector(1.5, 0.5, -0.5), &mx_1);
	scaling(vector(0.5, 0.5, 0.5), &mx_2);
	mxs_multiply(mx_1, mx_2, &transform);
	set_transform(_sphere, transform);
	_sphere->material = material();
	_sphere->material.color = color_3d(0.5, 1, 0.1);
	_sphere->material.specular = 0.3;
	_sphere->material.diffuse = 0.7;
}

// left ← sphere()
// left.transform ← translation(-1.5, 0.33, -0.75) * scaling(0.33, 0.33, 0.33)
// left.material ← material()
// left.material.color ← color(1, 0.8, 0.1)
// left.material.diffuse ← 0.7
// left.material.specular ← 0.3
void create_left_cylinder(void)
{
	t_object *_sphere;
	t_matrix mx_1;
	t_matrix mx_2;
	t_matrix transform;

	_sphere = cylinder();
	translation(vector(-1.5, 0.33, -0.75), &mx_1);
	scaling(vector(0.33, 0.33, 0.33), &mx_2);
	mxs_multiply(mx_1, mx_2, &transform);
	set_transform(_sphere, transform);
	_sphere->material = material();
	_sphere->material.color = color_3d(1, 0.8, 0.1);
	_sphere->material.specular = 0.3;
	_sphere->material.diffuse = 0.7;
}

// camera ← camera(100, 50, π/3)
// camera.transform ← view_transform(point(0, 1.5, -5),
//  point(0, 1, 0),
//  vector(0, 1, 0))
void set_demo_camera(void)
{
	t_matrix mx;

	// set_challenge_camera(100, 50, M_PI / 3.0);
	set_challenge_camera(500, 500, M_PI / 3.0);
	view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0), &mx);
	set_camera_transform(mx);
}

// world.light_source ← point_light(point(-10, 10, -10), color(1, 1, 1))
void set_demo_light(void)
{
	set_light(point(-10, 10, -10), 1.0);
}

void ray_tracer_v5_demo(void)
{
	create_floor();

	create_middle_sphere();
	create_right_sphere();
	create_left_cylinder();

	set_demo_light();
	set_demo_camera();

	render();

	mlx_image_save_ppm(camera_buffer(), "raytracer_v3.ppm");
	// initialize_window();
	// mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
	// while (true);
}
