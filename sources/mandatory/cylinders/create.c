/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 20:11:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_cylinder(t_object *cylinder, t_create_cylinder p)
{
	cylinder->shape = CYLINDER_SHAPE;
	cylinder->origin = p.origin;
	cylinder->normal = p.normal;
	cylinder->diameter = p.diameter;
	cylinder->radius = p.diameter / 2.0;
	cylinder->height = p.height;
	cylinder->minimum = -DBL_MAX;
	cylinder->maximum = DBL_MAX;
	cylinder->color_rgb = p.color;
	cylinder->color_3d = rgb_to_c3d(p.color);
	cylinder->intersect = &intersect_cylinder;
	cylinder->normal_at = &cylinder_normal_at;
}

t_object	*create_cylinder(t_create_cylinder params)
{
	t_object	*cylinder;

	cylinder = create_object();
	set_cylinder(cylinder, params);
	return (cylinder);
}

t_object	*cylinder(void)
{
	t_create_cylinder	params;

	params.origin = point(0, 0, 0);
	params.normal = vector(1, 0, 0);
	params.diameter = 2.0;
	params.height = 10.0;
	params.color = rgb_red();
	return (create_cylinder(params));
}
