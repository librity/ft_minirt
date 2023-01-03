/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 21:09:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	resolve_count(double delta)
{
	if (delta < 0.0)
		return (0);
	if (delta == 0.0)
		return (1);
	return (2);
}

t_intersect	intersect(t_object *sphere, t_ray ray)
{
	t_intersect_factors	f;
	t_intersect			result;

	f.sphere_to_ray = sub(ray.origin, sphere->origin);
	f.a = dot(ray.direction, ray.direction);
	f.b = 2.0 * dot(ray.direction, f.sphere_to_ray);
	f.c = dot(f.sphere_to_ray, f.sphere_to_ray)
		- sphere->radius * sphere->radius;
	f.delta = f.b * f.b - 4 * f.a * f.c;
	result.count = resolve_count(f.delta);
	if (f.delta < 0.0)
		return (result);
	result.roots[0] = (-f.b - sqrt(f.delta)) / (2.0 * f.a);
	result.roots[1] = (-f.b + sqrt(f.delta)) / (2.0 * f.a);
	return (result);
}

t_intersection	*intersection(double t, t_object *object)
{
	t_intersection	*intersection;

	intersection = ft_clalloc(lalloc(), 1, sizeof(t_intersection));
	intersection->t = t;
	intersection->object = object;
	return (intersection);
}

void	add_intersection(t_dlist **intersections, t_intersection *intersec)
{
	ft_dlst_addb_lalloc(lalloc(), intersections, intersec);
}
