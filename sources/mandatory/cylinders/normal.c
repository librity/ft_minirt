/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:24:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/02 18:57:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	cylinder_normal_at(t_object *cylinder, t_p3d point)
{
	double	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cylinder->maximum - EPSILON)
		return (vector(0, 1, 0));
	if (dist < 1 && point.y <= cylinder->minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vector(point.x, 0, point.z));
}
