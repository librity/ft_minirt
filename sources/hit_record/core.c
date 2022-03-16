/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:44:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/15 00:29:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_record(t_hit_record *target, t_hit_record record)
{
	target->intersection = record.intersection;
	target->normal = record.normal;
	target->translation = record.translation;
	target->front_face = record.front_face;
	target->color = record.color;
}

void	set_face_normal(t_ray ray,
						t_v3d outward_normal,
						t_hit_record *record)
{
	record->front_face = dot(ray.direction, outward_normal) < 0;
	if (record->front_face)
		record->normal = outward_normal;
	else
		record->normal = negative(outward_normal);
}
