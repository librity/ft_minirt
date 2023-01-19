/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:35:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 20:35:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_for_pixel(int px_x, int px_y)
{
	t_camera	cam;
	double		x_offset;
	double		y_offset;
	double		world_x;
	double		world_y;
	t_p3d		pixel;
	t_matrix	transform_inv;
	t_ray		px_ray;

	cam = camera();
	x_offset = (px_x + 0.5) * cam.pixel_size;
	y_offset = (px_y + 0.5) * cam.pixel_size;
	world_x = cam.half_width - x_offset;
	world_y = cam.half_height - y_offset;
	mx_inverse(cam.transform, 4, &transform_inv);
	pixel = mx_tuple_multiply(transform_inv, point(world_x, world_y, -1));
	px_ray.origin = mx_tuple_multiply(transform_inv, point(0, 0, 0));
	px_ray.direction = normalize(sub(pixel, px_ray.origin));
	return (px_ray);
}
