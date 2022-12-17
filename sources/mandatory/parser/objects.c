/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/17 14:28:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_sphere(char *line)
{
	t_p3d	origin;
	double	diameter;
	t_rgb	color;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	diameter = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	create_sphere(origin, diameter, color);
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
	(void)line;
}
