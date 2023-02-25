/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:37:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/23 22:01:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intxs	intersect_plane(t_object *plane, t_ray ray)
{
	t_intxs	result;
	double	t;

	result.count = 0;
	result.list = NULL;
	if (double_near_zero(ray.direction.y))
		return (result);
	t = -ray.origin.y / ray.direction.y;
	result.count = 1;
	create_intersection(&result.list, t, plane);
	return (result);
}
