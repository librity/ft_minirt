/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/16 00:44:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// static t_c3d	hit_background(t_ray ray, t_c3d background_tone)
// {
// 	t_c3d	ambient_light;
// 	t_c3d	cast;
// 	t_v3d	unit_direction;
// 	double	gradient;

// 	unit_direction = unit(ray.direction);
// 	gradient = 0.5 * (unit_direction.y + 1.0);
// 	ambient_light = color(1.0, 1.0, 1.0);
// 	ambient_light = scalar_times(1.0 - gradient, ambient_light);
// 	background_tone = scalar_times(gradient, background_tone);
// 	cast = add(ambient_light, background_tone);
// 	return (cast);
// }

static void	handle_hit(t_hit_record *record,
						t_hit_record current_record,
						double *closest_so_far,
						bool *hit_anything)
{
	*hit_anything = true;
	if (current_record.translation < *closest_so_far)
	{
		*closest_so_far = current_record.translation;
		set_record(record, current_record);
	}
}

bool	hit_any_spheres(t_minirt *ctl,
						t_ray ray,
						t_hit_record *record)
{
	t_hit_record	current_record;
	double			closest_so_far;
	int				sphere_count;
	bool			hit_anything;
	t_list			*spheres;

	spheres = ctl->spheres;
	if (spheres == NULL || spheres->content == NULL)
		return (false);
	closest_so_far = infinity();
	hit_anything = false;
	sphere_count = ft_lstsize(spheres);
	while (sphere_count--)
	{
		if (ray_hits_sphere((t_ray_hits_sphere){
				ray, spheres->content, &current_record, 0.001, closest_so_far}))
			handle_hit(record, current_record, &closest_so_far, &hit_anything);
		spheres = spheres->next;
	}
	return (hit_anything);
}

t_c3d	cast_ray(t_minirt *ctl, t_ray ray)
{
	t_hit_record	record;

	if (hit_any_spheres(ctl, ray, &record))
		return (render_sphere(ctl, ray, &record));
	// return (hit_background(ray, (t_c3d){0.5, 0.7, 1.0}));
	return (ctl->amb_light);
}
