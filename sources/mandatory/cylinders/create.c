/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 11:59:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_object	*new_cylinder(t_create_cylinder p)
{
	t_object	*cylinder;

	cylinder = ft_clalloc(lalloc(), 1, sizeof(t_object));
	cylinder->shape = CYLINDER_SHAPE;
	cylinder->origin = p.origin;
	cylinder->normal = p.normal;
	cylinder->diameter = p.diameter;
	cylinder->radius = p.diameter / 2.0;
	cylinder->height = p.height;
	cylinder->color_rgb = p.color;
	cylinder->color_3d = rgb_to_c3d(p.color);
	return (cylinder);
}

void	create_cylinder(t_create_cylinder params)
{
	t_object	*cylinder;

	cylinder = new_cylinder(params);
	create_object(cylinder);
}
