/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:44:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 18:21:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_record(t_hit_record *target, t_hit_record record)
{
	target->intersection = record.intersection;
	target->normal = record.normal;
	target->translation = record.translation;
	target->front_face = record.front_face;
	target->material = record.material;
}

void	set_face_normal(const t_ray ray,
						const t_vector_3d outward_normal,
						t_hit_record *record)
{
	record->front_face = dot(ray.direction, outward_normal) < 0;
	if (record->front_face)
		record->normal = outward_normal;
	else
		record->normal = negative(outward_normal);
}
