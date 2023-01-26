/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 18:52:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	is_shadowed(t_p3d point)
{
	t_v3d	ray_vector;
	t_ray	shadow_ray;
	t_light	_light;
	t_intxs	xs;
	t_intx	*inter;
	double	distance;

	_light = light();
	ray_vector = sub(_light.origin, point);
	distance = magnitude(ray_vector);
	shadow_ray = ray(point, normalize(ray_vector));
	xs = intersect_world(shadow_ray);
	if (xs.count == 0)
		return (false);
	inter = hit(xs);
	if (inter == NULL)
		return (false);
	if (inter->t < distance)
		return (true);
	return (false);
}
