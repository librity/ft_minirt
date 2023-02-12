/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:10:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


t_c3d	lighting(t_material material, t_light light, t_lighting_params p)
{
	p.effective_color = product(material.color, light.intensity);
	p.ambient = scalar_times(material.ambient, p.effective_color);
	if (p.in_shadow)
	{
		p.result = p.ambient;
		p.result.type = 0;
		return (p.result);
	}

	p.light_vector = normalize(sub(light.origin, p.point));
	p.light_dot_normal = dot(p.light_vector, p.normal);

	if (p.light_dot_normal < 0.0)
	{
		p.diffuse = color(0.0, 0.0, 0.0);
		p.specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		p.diffuse = scalar_times(material.diffuse * p.light_dot_normal, p.effective_color);

		p.reflection = reflect(neg(p.light_vector), p.normal);
		p.reflect_dot_eye = dot(p.reflection, p.eye);
		if (p.reflect_dot_eye <= 0.0)
			p.specular = color(0.0, 0.0, 0.0);
		else
		{
			p.factor = pow(p.reflect_dot_eye, material.shininess);
			p.specular = scalar_times(material.specular * p.factor, light.intensity);
		}
	}

	p.result = add(p.ambient, p.diffuse);
	p.result = add(p.result, p.specular);
	p.result.type = 0;
	return (p.result);
}


