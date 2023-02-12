/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_v5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:40:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:37:03 by lpaulo-m         ###   ########.fr       */
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

void	create_floor(void)
{
	t_object	*_plane;

	_plane = plane();
	_plane->material = wall_material();
}

void	create_middle_sphere(void)
{
	t_object	*_sphere;
	t_matrix	mx;

	_sphere = sphere();
	translation(vector(-0.5, 1, 0.5), &mx);
	set_transform(_sphere, mx);
	_sphere->material = material();
	_sphere->material.color = color_3d(0.1, 1, 0.5);
	_sphere->material.specular = 0.3;
	_sphere->material.diffuse = 0.7;
}

void	create_right_sphere(void)
{
	t_object	*_sphere;
	t_matrix	mx_1;
	t_matrix	mx_2;
	t_matrix	transform;

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

void	create_left_cylinder(void)
{
	t_object	*_cyl;
	t_matrix	mx_1;
	t_matrix	mx_2;
	t_matrix	transform;

	_cyl = cylinder();
	_cyl->minimum = 1;
	_cyl->maximum = 2;
	_cyl->closed = true;
	translation(vector(-1.5, 0.33, -0.75), &mx_1);
	scaling(vector(0.33, 0.33, 0.33), &mx_2);
	mxs_multiply(mx_1, mx_2, &transform);
	set_transform(_cyl, transform);
	_cyl->material = material();
	_cyl->material.color = color_3d(1, 0.8, 0.1);
	_cyl->material.specular = 0.3;
	_cyl->material.diffuse = 0.7;
}

void	set_demo_camera(void)
{
	t_matrix	mx;

	set_challenge_camera(50, 50, M_PI / 3.0);
	view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0),
		&mx);
	set_camera_transform(mx);
}

void	set_demo_light(void)
{
	set_light(point(-10, 10, -10), 1.0);
}

void	ray_tracer_v5_demo(void)
{
	create_floor();
	create_middle_sphere();
	create_right_sphere();
	create_left_cylinder();
	set_demo_light();
	set_demo_camera();
	render();
	initialize_window();
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
}
