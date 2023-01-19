/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:24:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/19 20:34:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*new_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*sphere;

	sphere = ft_clalloc(world_lalloc(), 1, sizeof(t_object));
	sphere->shape = SPHERE_SHAPE;
	sphere->origin = origin;
	sphere->diameter = diameter;
	sphere->radius = diameter / 2.0;
	sphere->color_rgb = color;
	sphere->color_3d = rgb_to_c3d(color);
	sphere->material = material();
	mx_set_identity(&(sphere->transform));
	return (sphere);
}

t_object	*sphere(void)
{
	return (create_sphere(point(0, 0, 0), 2.0, rgb_red()));
}

t_object	*create_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*sphere;

	sphere = new_sphere(origin, diameter, color);
	create_object(sphere);
	return (sphere);
}
