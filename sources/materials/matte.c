/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matte.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:23:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:22:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	*make_matte(t_c3d albedo)
{
	t_material	*new;

	new = prototype_material(&scatter_matte);
	new->albedo = albedo;
	return (new);
}

bool	scatter_matte(t_ray incident_ray,
					void *void_record,
					t_c3d *attenuation,
					t_ray *scattered_ray)
{
	t_hit_record	*record;
	t_material	*material;
	t_v3d			scatter_direction;

	record = void_record;
	material = record->material;
	(void)incident_ray;
	scatter_direction = add(record->normal, random_unit_vector());
	if (near_zero(scatter_direction))
		scatter_direction = record->normal;
	*scattered_ray = ray(record->intersection, scatter_direction);
	*attenuation = material->albedo;
	return (true);
}
