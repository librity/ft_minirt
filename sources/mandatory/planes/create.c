/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:01:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_plane(t_object *plane, t_p3d origin, t_p3d normal, t_rgb color)
{
	plane->shape = PLANE_SHAPE;
	plane->material.color = rgb_to_c3d(color);
	plane->intersect = &intersect_plane;
	plane->normal_at = &plane_normal_at;
	plane->normal = y_axis_normal();
	translate_object(plane, origin);
	fast_rotate_object(plane, normal);
	plane->origin = space_origin();
}

t_object	*create_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*plane;

	(void)normal;
	plane = create_object();
	set_plane(plane, origin, normal, color);
	return (plane);
}

t_object	*plane(void)
{
	t_object	*_plane;

	_plane = create_plane(point(0, 0, 0), vector(1, 0, 0), rgb_red());
	return (_plane);
}
