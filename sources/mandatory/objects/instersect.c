/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/02 18:46:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intx	*new_intersection(double t, t_object *object)
{
	t_intx	*intersection;

	intersection = ft_clalloc(ray_lalloc(), 1, sizeof(t_intx));
	intersection->t = t;
	intersection->object = object;
	return (intersection);
}

void	create_intersection(t_dlist **intersections, double t, t_object *object)
{
	t_intx	*intersection;

	intersection = new_intersection(t, object);
	ft_dlst_addb_lalloc(ray_lalloc(), intersections, intersection);
}

void	add_intersection(t_intxs *xs, double t, t_object *object)
{
	create_intersection(&(xs->list), t, object);
	xs->count++;
}

t_intxs	intersect_object(t_object *object, t_ray ray)
{
	ray = inverse_transform(ray, object->transform);
	return (object->intersect(object, ray));
}

t_intxs	empty_intersections(void)
{
	return ((t_intxs){0, NULL});
}
