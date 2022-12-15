/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:24:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 21:42:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_object	*new_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*sphere;

	sphere = ft_scalloc(1, sizeof(t_object));
	sphere->shape = SPHERE_SHAPE;
	sphere->origin = origin;
	sphere->diameter = diameter;
	sphere->color_rgb = color;
	return (sphere);
}

void	create_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*sphere;

	sphere = new_sphere(origin, diameter, color);
	ft_dlst_add_lalloc(lalloc(), objects(), sphere);
}
