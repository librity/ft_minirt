/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 21:52:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_v3d	point_ray(t_camera *camera, double horz_offset,
		double vert_offset)
{
	t_v3d	direction;

	direction = camera->ll_corner;
	direction = add(direction, scalar_times(horz_offset, camera->horizontal));
	direction = add(direction, scalar_times(vert_offset, camera->vertical));
	direction = sub(direction, camera->origin);
	return (direction);
}

t_ray	get_ray(t_minirt *ctl, t_camera *camera, int x, int y)
{
	t_ray	ray;
	double	horz_offset;
	double	vert_offset;

	ray.origin = camera->origin;
	horz_offset = (double)(x) / (ctl->width);
	vert_offset = (double)(y) / (ctl->height);
	ray.direction = point_ray(camera, horz_offset, vert_offset);
	return (ray);
}
