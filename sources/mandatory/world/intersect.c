/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/19 20:24:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intxs	intersect_world(t_ray ray)
{
	t_dlist		*node;
	t_dlist		*last_intersection;
	t_object	*object;
	t_intxs		_intersect;
	t_intxs		result;

	result.count = 0;
	result.list = NULL;
	node = *objects();
	// ft_debug("dasdasd");
	while (node != NULL)
	{
		object = node->content;
		_intersect = intersect(object, ray);
		result.count += _intersect.count;
		if (_intersect.list != NULL)
		{
			if (result.list == NULL)
				result.list = _intersect.list;
			else
			{
				last_intersection = ft_dlstlast(result.list);
				last_intersection->next = _intersect.list;
				_intersect.list->prev = last_intersection;
			}
		}
		node = node->next;
	}
	if (result.list != NULL)
		sort_intersections(&result.list);
	return (result);
}
