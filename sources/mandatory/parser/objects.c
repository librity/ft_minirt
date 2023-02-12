/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:59:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_sphere(char *line)
{
	t_p3d		origin;
	double		diameter;
	t_rgb		color;
	t_object	*_sphere;
	t_matrix	translation_mx;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	diameter = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	_sphere = create_sphere(point(0, 0, 0), diameter, color);
	translation((t_v3d)origin, &translation_mx);
	multiply_transform(_sphere, translation_mx);
}

void	parse_plane(char *line)
{
	t_p3d	origin;
	t_p3d	normal;
	t_rgb	color;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	normal = parse_vector(line);
	line = skip_field(line);
	color = parse_color(line);
	create_plane(origin, normal, color);
}

void	parse_cylinder(char *line)
{
	t_create_cylinder	params;

	line = skip_field(line);
	params.origin = parse_point(line);
	line = skip_field(line);
	params.normal = parse_vector(line);
	line = skip_field(line);
	params.diameter = ft_atof(line);
	line = skip_field(line);
	params.height = ft_atof(line);
	line = skip_field(line);
	params.color = parse_color(line);
	create_cylinder(params);
}
