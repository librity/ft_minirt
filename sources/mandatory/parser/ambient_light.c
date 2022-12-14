/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:08:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_ambient_light(char *line)
{
	double	brightness;
	t_rgb	color;

	line++;
	line = ft_skip_whitespace(line);
	brightness = ft_atof(line);
	line = ft_skip_nonwhitespace(line);
	line = ft_skip_whitespace(line);
	color = parse_color(line);
	set_ambient_light(brightness, color);
}
