/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:49:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 01:13:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	point_ray(t_camera *camera,
				double horizontal,
				double vertical)
{
	t_v3d	direction;

	direction = camera->lower_left_corner;
	direction = add(direction, scalar_times(horizontal, camera->horizontal));
	direction = add(direction, scalar_times(vertical, camera->vertical));
	direction = sub(direction, camera->origin);
	return (direction);
}

t_ray	set_ray(t_camera *camera,
				double horizontal,
				double vertical)
{
	t_ray	ray;

	ray.origin = camera->origin;
	ray.direction = point_ray(camera, horizontal, vertical);
	return (ray);
}
