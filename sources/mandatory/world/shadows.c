/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:58:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	is_shadowed(t_p3d point)
{
	t_is_shadowed_aux	p;

	p.light = light();
	p.ray_vector = sub(p.light.origin, point);
	p.distance = magnitude(p.ray_vector);
	p.shadow_ray = ray(point, normalize(p.ray_vector));
	p.xs = intersect_world(p.shadow_ray);
	if (p.xs.count == 0)
		return (false);
	p.inter = hit(p.xs);
	if (p.inter == NULL)
		return (false);
	if (p.inter->t < p.distance)
		return (true);
	return (false);
}
