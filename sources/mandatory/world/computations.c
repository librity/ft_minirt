/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:30:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray_comp	prepare_computations(t_intx intersect, t_ray _ray)
{
	t_ray_comp	comps;

	comps.t = intersect.t;
	comps.object = intersect.object;
	comps.point = position(_ray, intersect.t);
	comps.eyev = neg(_ray.direction);
	comps.normalv = object_normal_at(intersect.object, comps.point);
	if (dot(comps.eyev, comps.normalv) < 0)
	{
		comps.inside = true;
		comps.normalv = neg(comps.normalv);
	}
	else
		comps.inside = false;
	comps.over_point = add(comps.point, scalar_times(EPSILON, comps.normalv));
	return (comps);
}
