/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/10 19:40:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	lighting(t_material material, t_light light, t_p3d point, t_v3d eye, t_v3d normal)
{
	t_c3d	effective_color;
	t_c3d	ambient;
	t_v3d	light_vector;
	t_v3d	reflection;
	double	light_dot_normal;
	t_c3d	diffuse;
	t_c3d	specular;
	double	reflect_dot_eye;
	double	factor;
	t_c3d	result;

	light_vector = normalize(sub(light.origin, point));

	effective_color = product(material.color, light.intensity);
	ambient = scalar_times(material.ambient, effective_color);
	light_dot_normal = dot(light_vector, normal);

	if (light_dot_normal < 0.0)
	{
		diffuse = color(0.0, 0.0, 0.0);
		specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		diffuse = scalar_times(material.diffuse * light_dot_normal, effective_color);

		reflection = reflect(neg(light_vector), normal);
		reflect_dot_eye = dot(reflection, eye);
		if (reflect_dot_eye <= 0.0)
			specular = color(0.0, 0.0, 0.0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = scalar_times(material.specular * factor, light.intensity);
		}
	}

	result = add(ambient, diffuse);
	result = add(result, specular);
	result.type = 0;
	return (result);
}


