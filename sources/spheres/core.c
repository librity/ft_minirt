/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:22:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*new_sphere(t_p3d center, double radius, t_material *material)
{
	t_sphere	*new;

	new = (t_sphere *)ft_salloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->material = material;
	return (new);
}

void	free_spheres(t_list **spheres)
{
	ft_lstclear(spheres, &free);
}

t_c3d	render_sphere(t_ray ray,
							t_hit_record *record,
							t_list *spheres,
							int depth)
{
	t_ray						scattered;
	t_c3d					attenuation;
	t_c3d					scattered_color;
	t_c3d					attenuated;
	t_scatter_callback	scatteres_ray;

	scatteres_ray = record->material->scattered;
	if (scatteres_ray(ray, record, &attenuation, &scattered))
	{
		scattered_color = cast_ray(scattered, spheres, depth - 1);
		attenuated = product(attenuation, scattered_color);
		return (attenuated);
	}
	return (color(0.0, 0.0, 0.0));
}
