/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:18:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	inspect_intersections(t_dlist **intersections)
{
	t_dlist	*node;

	node = *intersections;
	while (node != NULL)
	{
		printf("t = %f\n", ((t_intx *)node->content)->t);
		node = node->next;
	}
}

static void	add_intersections(t_intxs *result, t_intxs intersections)
{
	t_dlist	*last_intersection;

	if (intersections.list == NULL)
		return ;
	result->count += intersections.count;
	if (result->list == NULL)
	{
		result->list = intersections.list;
		return ;
	}
	last_intersection = ft_dlstlast(result->list);
	last_intersection->next = intersections.list;
	intersections.list->prev = last_intersection;
}

t_intxs	intersect_world(t_ray ray)
{
	t_dlist		*node;
	t_object	*object;
	t_intxs		intersections;
	t_intxs		result;

	result = empty_intersections();
	node = *objects();
	while (node != NULL)
	{
		object = node->content;
		intersections = intersect_object(object, ray);
		add_intersections(&result, intersections);
		node = node->next;
	}
	if (result.list != NULL)
		sort_intersections(&result.list);
	return (result);
}
