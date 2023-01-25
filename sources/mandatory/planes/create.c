/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 20:21:31 by lpaulo-m         ###   ########.fr       */
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
}

t_object	*create_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*plane;

	plane = create_object();
	set_plane(plane, origin, normal, color);
	return (plane);
}
