/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 18:42:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_rgb	parse_color(char *line)
{
	char	**tokens;
	t_rgb	color;

	tokens = ft_split(line, ',');
	color.red = ft_atoi(tokens[0]);
	color.green = ft_atoi(tokens[1]);
	color.blue = ft_atoi(tokens[2]);
	ft_free_strarr(tokens);
	return (color);
}

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
