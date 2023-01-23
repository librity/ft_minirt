/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/23 19:29:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	shade_hit(t_ray_comp comp)
{
	bool	in_shadow;

	in_shadow = is_shadowed(comp.over_point);
	return (lighting(comp.object->material, light(), comp.over_point, comp.eyev,
			comp.normalv, in_shadow));
}
