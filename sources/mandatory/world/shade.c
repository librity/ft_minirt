/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:12:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	shade_hit(t_ray_comp comp)
{
	t_lighting_params	lighting_params;

	lighting_params.point = comp.over_point;
	lighting_params.eye = comp.eyev;
	lighting_params.normal = comp.normalv;
	lighting_params.in_shadow = is_shadowed(comp.over_point);
	return (lighting(comp.object->material, light(), lighting_params));
}
