/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:37:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:45:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intxs	intersect_plane(t_object *object, t_ray ray)
{
	t_intxs	result;

	(void)object;
	result.count = 0;
	result.list = NULL;
	if (double_near_zero(ray.direction.y))
		return (result);
	return (result);
}
