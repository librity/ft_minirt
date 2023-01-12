/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/12 20:03:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intersect	intersect_world(t_ray ray)
{
	t_dlist		*node;
	t_dlist		*last_intersection;
	t_object	*object;
	t_intersect	_intersect;
	t_intersect	result;

	result.count = 0;
	result.intersections = NULL;
	node = *objects();
	while (node != NULL)
	{
		ft_debug("node = %p", node);
		object = node->content;
		_intersect = intersect(object, ray);
		result.count += _intersect.count;
		if (result.intersections == NULL)
			result.intersections = _intersect.intersections;
		else
		{
			last_intersection = ft_dlstlast(result.intersections);
			last_intersection->next = result.intersections;
			result.intersections->prev = last_intersection;
		}
		node = node->next;
	}
	return (result);
}
