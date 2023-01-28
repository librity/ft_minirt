/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/28 18:00:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	t_intx_aux	f;
	t_intxs		result;

	result.list = NULL;
	result.count = 0;
	f.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (double_near_zero(f.a))
		return (empty_intersections());
	f.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z
		* ray.direction.z;
	f.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1.0;
	f.disk = f.b * f.b - 4.0 * f.a * f.c;
	if (f.disk < 0.0)
		return (empty_intersections());
	create_intersection(&result.list, 1, cylinder);
	return (result);
}
