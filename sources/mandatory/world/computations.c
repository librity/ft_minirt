/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/17 18:35:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray_comp	prepare_computations(t_intx intersect, t_ray _ray)
{
	t_ray_comp	computations;

	computations.t = intersect.t;
	computations.object = intersect.object;
	computations.point = position(_ray, intersect.t);
	computations.eyev = neg(_ray.direction);
	computations.normalv = normal_at(intersect.object, computations.point);
	if (dot(computations.eyev, computations.normalv) < 0)
	{
		computations.inside = true;
		computations.normalv = neg(computations.normalv);
	}
	else
		computations.inside = false;
	return (computations);
}
