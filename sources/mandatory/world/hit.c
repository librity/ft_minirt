/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:09:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/28 17:47:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intx	*hit(t_intxs intersect)
{
	t_dlist			*node;
	t_intx			*current;
	t_intx			*min_positive;
	t_intx			max_intersection;

	node = intersect.list;
	max_intersection.t = DBL_MAX;
	min_positive = &max_intersection;
	while (node != NULL)
	{
		current = node->content;
		if (current->t < 0.0)
		{
			node = node->next;
			continue ;
		}
		if (current->t < min_positive->t)
			min_positive = current;
		node = node->next;
	}
	if (min_positive == &max_intersection)
		return (NULL);
	return (min_positive);
}
