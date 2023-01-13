/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:33:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 18:49:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// wall_z ← 10.0
// wall_size ← 7.0
// pixel_size ← wall_size / canvas_pixels
// half ← wall_size / 2
// ray_origin ← point(0, 0, -5)

// # for each row of pixels in the canvas
// for y ← 0 to canvas_pixels - 1
// » # compute the world y coordinate (top = +half, bottom = -half)
// » world_y ← half - pixel_size * y
//  # for each pixel in the row
//  for x ← 0 to canvas_pixels - 1
//  # compute the world x coordinate (left = -half, right = half)
//  world_x ← -half + pixel_size * x
//  # describe the point on the wall that the ray will target
//  position ← point(world_x, world_y, wall_z)
//  r ← ray(ray_origin, normalize(position - ray_origin))
//  xs ← intersect(shape, r)
//  if hit(xs) is defined
//  write_pixel(canvas, x, y, color)
//  end if
//  end for
// end for

void	ray_tracer_v1_demo()
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
	t_p3d		position;
	t_intersections	_intersect;
	t_intersection	*inter;
	t_rgb		pixel_color;

	img = camera_buffer();
	_sphere = sphere();
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

			position = point(world_x, world_y, wall_z);
			_ray = ray(ray_origin, normalize(sub(position, ray_origin)));
			_intersect = intersect(_sphere, _ray);
			inter = hit(_intersect);

			if (inter == NULL)
				pixel_color = rgb_black();
			else
				pixel_color = _sphere->color_rgb;
			mlx_image_draw_rgb(img, pixel_color, x, y);

			x++;
		}
		y++;
	}
	mlx_image_save_ppm(img, "ray_tracer_v1_demo.ppm");
}
