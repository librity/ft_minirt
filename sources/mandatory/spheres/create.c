/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:24:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 20:21:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_sphere(t_object *sphere,
				t_p3d origin, double diameter, t_rgb color)
{
	sphere->shape = SPHERE_SHAPE;
	sphere->origin = origin;
	sphere->diameter = diameter;
	sphere->radius = diameter / 2.0;
	sphere->color_rgb = color;
	sphere->color_3d = rgb_to_c3d(color);
	sphere->intersect = &intersect_sphere;
	sphere->normal_at = &sphere_normal_at;
}

t_object	*create_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*sphere;

	sphere = create_object();
	set_sphere(sphere, origin, diameter, color);
	return (sphere);
}

t_object	*sphere(void)
{
	return (create_sphere(point(0, 0, 0), 2.0, rgb_red()));
}
