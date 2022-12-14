/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 20:47:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_ambient_light(char *line)
{
	double	brightness;
	t_rgb	color;

	line = skip_field(line);
	brightness = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	set_ambient_light(brightness, color);
}

void	parse_camera(char *line)
{
	t_p3d	origin;
	t_v3d	orientation;
	double	horz_fov_deg;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	orientation = parse_vector(line);
	line = skip_field(line);
	horz_fov_deg = ft_atof(line);
	set_camera(origin, orientation, horz_fov_deg);
}

void	parse_light(char *line)
{
	t_p3d	origin;
	double	brightness;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	brightness = ft_atof(line);
	set_light(origin, brightness);
}
