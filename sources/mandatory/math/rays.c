/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:37:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 18:56:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_3d(t_p3d origin, t_v3d direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_ray	ray(t_p3d origin, t_v3d direction)
{
	return (ray_3d(origin, direction));
}

t_p3d	ray_at(t_ray r, double translation)
{
	t_p3d	result;

	result = scalar_times(translation, r.direction);
	add(r.origin, result);
	return (result);
}

void	inspect_ray(t_ray r)
{
	inspect_tuple(r.origin);
	inspect_tuple(r.direction);
}
