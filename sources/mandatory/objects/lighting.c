/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:14:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_c3d	get_diffuse_color(t_material m, t_lighting_params p)
{
	t_c3d	diffuse_color;

	diffuse_color = scalar_times(p.light_dot_normal * m.diffuse,
			p.effective_color);
	return (diffuse_color);
}

static t_c3d	get_specular_color(t_material m, t_light light,
		t_lighting_params p)
{
	t_v3d	reflection;
	t_c3d	specular_color;
	double	reflect_dot_eye;
	double	factor;

	reflection = reflect(neg(p.light_vector), p.normal);
	reflect_dot_eye = dot(reflection, p.eye);
	if (reflect_dot_eye <= 0.0)
		specular_color = color_3d(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, m.shininess);
		specular_color = scalar_times(factor * m.specular, light.intensity);
	}
	return (specular_color);
}

static void	get_diff_spec_color(t_material m, t_light light,
		t_lighting_params *p)
{
	p->light_dot_normal = dot(p->light_vector, p->normal);
	if (p->light_dot_normal < 0.0)
	{
		p->diffuse = color_3d(0, 0, 0);
		p->specular = color_3d(0, 0, 0);
	}
	else
	{
		p->diffuse = get_diffuse_color(m, *p);
		p->specular = get_specular_color(m, light, *p);
	}
}

t_c3d	lighting(t_material material, t_light light, t_lighting_params p)
{
	t_c3d	result;

	p.light_vector = normalize(sub(light.origin, p.point));
	p.effective_color = product(material.color, light.intensity);
	p.effective_color = product(p.effective_color, ambient_light().intensity);
	p.ambient = scalar_times(material.ambient, p.effective_color);
	if (p.in_shadow == true)
		return (p.ambient);
	get_diff_spec_color(material, light, &p);
	result = add(p.ambient, p.diffuse);
	result = add(result, p.specular);
	result.type = 0;
	return (result);
}
