/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 19:27:28 by lpaulo-m         ###   ########.fr       */
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
