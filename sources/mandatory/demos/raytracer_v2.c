/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:33:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 18:49:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_tracer_v2_demo()
{
	t_mlx_image	*img;
	t_object	*_sphere;
	int			x;
	int			y;
	double		wall_size;
	double		wall_z;
	t_ray		_ray;
	double		pixel_size;
	double		half_wall;
	double		world_y;
	double		world_x;
	t_p3d		ray_origin;
	t_p3d		_position;
	t_intersections	_intersect;
	t_intersection	*_hit;
	t_rgb		pixel_color;
	t_light		_light;
	t_p3d		_point;
	t_v3d		_normal;
	t_v3d		_eye;
	t_c3d		result_color;


	img = camera_buffer();
	_sphere = sphere();
	_light = point_light(point(-10, 10, -10), 1.0, color_rgb(255, 255, 255));
	_sphere->material.color = color_3d(1, 0.2, 1);
	wall_size = 7.0;
	wall_z = 10.0;
	pixel_size = wall_size / (double)img->width;
	half_wall = wall_size * 0.5;
	ray_origin = point(0, 0, -5);

	y = 0;
	while (y < img->width)
	{
		world_y = half_wall - pixel_size * y;
		x = 0;
		while (x < img->height)
		{
			world_x = -half_wall + pixel_size * x;

			_position = point(world_x, world_y, wall_z);
			_ray = ray(ray_origin, normalize(sub(_position, ray_origin)));
			_intersect = intersect(_sphere, _ray);
			_hit = hit(_intersect);

			if (_hit == NULL)
				pixel_color = rgb_black();
			else
			{
				_point = position(_ray, _hit->t);
				_normal = normal_at(_hit->object, _point);
				_eye = neg(_ray.direction);

				result_color = lighting(_hit->object->material, _light, _point, _eye, _normal);
				pixel_color = c3d_to_rgb(result_color);
			}
			mlx_image_draw_rgb(img, pixel_color, x, y);

			x++;
		}

		ft_putchar('.');
		y++;
	}
	mlx_image_save_ppm(img, "ray_tracer_v2_demo.ppm");
}
