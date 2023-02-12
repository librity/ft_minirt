/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:30:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static bool	check_cap(t_ray ray, double temp)
{
	double	x;
	double	z;

	x = ray.origin.x + temp * ray.direction.x;
	z = ray.origin.z + temp * ray.direction.z;
	return ((x * x + z * z) <= 1);
}

static void	intersect_caps(t_object *cylinder, t_ray ray, t_intxs *xs)
{
	double	t;

	if (!cylinder->closed || double_near_zero(ray.direction.y))
		return ;
	t = (cylinder->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t) == true)
		add_intersection(xs, t, cylinder);
	t = (cylinder->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t) == true)
		add_intersection(xs, t, cylinder);
}

static t_intx_aux	cylinder_quadratic(t_ray ray)
{
	t_intx_aux	f;

	f.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	f.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z
		* ray.direction.z;
	f.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1.0;
	f.delta = f.b * f.b - 4.0 * f.a * f.c;
	return (f);
}

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	t_intx_aux	f;
	t_intxs		result;

	result = empty_intersections();
	f = cylinder_quadratic(ray);
	if (double_near_zero(f.a))
	{
		intersect_caps(cylinder, ray, &result);
		return (result);
	}
	if (f.delta < 0.0)
		return (result);
	f.root_1 = (-f.b - sqrt(f.delta)) / (2 * f.a);
	f.root_2 = (-f.b + sqrt(f.delta)) / (2 * f.a);
	if (f.root_1 > f.root_2)
		ft_swap_d(&f.root_1, &f.root_2);
	f.y0 = ray.origin.y + f.root_1 * ray.direction.y;
	if (f.y0 > cylinder->minimum && f.y0 < cylinder->maximum)
		add_intersection(&result, f.root_1, cylinder);
	f.y1 = ray.origin.y + f.root_2 * ray.direction.y;
	if (f.y1 > cylinder->minimum && f.y1 < cylinder->maximum)
		add_intersection(&result, f.root_2, cylinder);
	intersect_caps(cylinder, ray, &result);
	return (result);
}
