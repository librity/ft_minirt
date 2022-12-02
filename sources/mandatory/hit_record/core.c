/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:44:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 22:05:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_record(t_hit_rec *target, t_hit_rec record)
{
	target->intersection = record.intersection;
	target->normal = record.normal;
	target->translation = record.translation;
	target->front_face = record.front_face;
	target->color_3d = record.color_3d;
}

void	set_face_normal(t_ray ray,
						t_v3d outward_normal,
						t_hit_rec *record)
{
	record->front_face = dot(ray.direction, outward_normal) < 0;
	if (record->front_face)
		record->normal = outward_normal;
	else
		record->normal = negative(outward_normal);
}
