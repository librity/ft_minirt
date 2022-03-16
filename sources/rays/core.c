/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 23:25:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray(t_p3d origin, t_v3d direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_p3d	ray_at_t(double translation, t_ray ray)
{
	t_v3d	reach;

	reach = scalar_times(translation, ray.direction);
	return (add(ray.origin, reach));
}

t_ray	get_ray(t_minirt *ctl,
				t_camera camera,
				int row,
				int column)
{
	double	horizontal_direction;
	double	vertical_direction;

	horizontal_direction = (double)(column) / (ctl->width - 1);
	vertical_direction = (double)(row) / (ctl->height - 1);
	return (set_ray(camera, horizontal_direction, vertical_direction));
}
