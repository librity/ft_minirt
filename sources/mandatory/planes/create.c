/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:38:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_plane(t_object *plane, t_p3d origin, t_p3d normal, t_rgb color)
{
	plane->shape = PLANE_SHAPE;
	plane->origin = origin;
	plane->normal = normal;
	plane->color_rgb = color;
	plane->color_3d = rgb_to_c3d(color);
	plane->intersect = &intersect_plane;
	plane->normal_at = &plane_normal_at;
}

t_object	*create_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*plane;

	plane = create_object();
	set_plane(plane, origin, normal, color);
	return (plane);
}

t_object	*plane(void)
{
	t_object	*_plane;

	_plane = create_plane(point(0, 0, 0), vector(0, 1, 0), rgb_red());
	return (_plane);
}
