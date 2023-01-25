/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 18:37:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	color_at(t_ray _ray)
{
	t_intxs		xs;
	t_intx		*inter;
	t_ray_comp	ray_comp;
	t_c3d		ray_color;

	xs = intersect_world(_ray);
	inter = hit(xs);
	if (inter == NULL)
	{
		free_ray_lalloc();
		return (color_3d(0, 0, 0));
	}
	ray_comp = prepare_computations(*inter, _ray);
	ray_color = shade_hit(ray_comp);
	free_ray_lalloc();
	return (ray_color);
}
