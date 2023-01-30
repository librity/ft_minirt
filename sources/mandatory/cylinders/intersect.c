/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 20:11:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	t_intx_aux	f;
	t_intxs		result;

	result = empty_intersections();
	f.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (double_near_zero(f.a))
		return (result);
	f.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z
		* ray.direction.z;
	f.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1.0;
	f.delta = f.b * f.b - 4.0 * f.a * f.c;
	if (f.delta < 0.0)
		return (result);
	f.root_1 = (-f.b - sqrt(f.delta)) / (2 * f.a);
	f.root_2 = (-f.b + sqrt(f.delta)) / (2 * f.a);
	if (f.root_1 > f.root_2)
		ft_swap_d(&f.root_1, &f.root_2);
	f.y0 = ray.origin.y + f.root_1 * ray.direction.y;
	if (f.y0 > cylinder->minimum && f.y0 < cylinder->maximum)
	{
		create_intersection(&result.list, f.root_1, cylinder);
		result.count++;
	}
	f.y1 = ray.origin.y + f.root_2 * ray.direction.y;
	if (f.y1 > cylinder->minimum && f.y1 < cylinder->maximum)
	{
		create_intersection(&result.list, f.root_2, cylinder);
		result.count++;
	}
	return (result);
}
