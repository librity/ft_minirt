/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 19:12:25 by lpaulo-m         ###   ########.fr       */
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
	f.delta = f.b * f.b - 4.0 * f.a * f.c;
	if (f.delta < 0.0)
		return (empty_intersections());
	f.root_1 = (-f.b - sqrt(f.delta)) / (2 * f.a);
	f.root_2 = (-f.b + sqrt(f.delta)) / (2 * f.a);
	create_intersection(&result.list, f.root_1, cylinder);
	create_intersection(&result.list, f.root_2, cylinder);
	result.count = 2;
	return (result);
}
