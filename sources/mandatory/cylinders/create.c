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

static void	set_cylinder(t_object *cylinder, t_create_cylinder p)
{
	cylinder->shape = CYLINDER_SHAPE;
	cylinder->minimum = -p.height / 2.0;
	cylinder->maximum = p.height / 2.0;
	cylinder->closed = true;
	cylinder->material.color = rgb_to_c3d(p.color);
	cylinder->intersect = &intersect_cylinder;
	cylinder->normal_at = &cylinder_normal_at;
	cylinder->normal = y_axis_normal();
	translate_object(cylinder, p.origin);
	fast_rotate_object(cylinder, p.normal);
	scale_object(cylinder, vector(p.diameter / 2, 1, p.diameter / 2));
	cylinder->origin = space_origin();
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
