/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:35:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:00:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_for_pixel(int px_x, int px_y)
{
	t_ray_for_pixel_aux	p;

	p.cam = camera();
	p.x_offset = (px_x + 0.5) * p.cam.pixel_size;
	p.y_offset = (px_y + 0.5) * p.cam.pixel_size;
	p.world_x = p.cam.half_width - p.x_offset;
	p.world_y = p.cam.half_height - p.y_offset;
	mx_inverse(p.cam.transform, 4, &p.transform_inv);
	p.pixel = mx_tuple_multiply(p.transform_inv,
			point(p.world_x, p.world_y, -1));
	p.px_ray.origin = mx_tuple_multiply(p.transform_inv, point(0, 0, 0));
	p.px_ray.direction = normalize(sub(p.pixel, p.px_ray.origin));
	return (p.px_ray);
}
