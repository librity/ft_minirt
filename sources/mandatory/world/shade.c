/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/23 18:26:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	shade_hit(t_ray_comp comp)
{
	return (lighting(comp.object->material, light(), comp.point, comp.eyev,
			comp.normalv, false));
}
