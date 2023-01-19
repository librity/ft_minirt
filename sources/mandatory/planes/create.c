/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/17 19:12:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_object	*new_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*plane;

	plane = ft_clalloc(world_lalloc(), 1, sizeof(t_object));
	plane->shape = PLANE_SHAPE;
	plane->origin = origin;
	plane->normal = normal;
	plane->color_rgb = color;
	plane->color_3d = rgb_to_c3d(color);
	return (plane);
}

void	create_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*plane;

	plane = new_plane(origin, normal, color);
	create_object(plane);
}
