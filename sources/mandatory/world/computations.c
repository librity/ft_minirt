/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 19:20:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray_comps	prepare_computations(t_intx intersect, t_ray _ray)
{
	t_ray_comps	computations;

	computations.t = intersect.t;
	computations.object = intersect.object;
	computations.point = position(_ray, intersect.t);
	computations.eyev = neg(_ray.direction);
	computations.normalv = normal_at(intersect.object, computations.point);
	return (computations);
}
