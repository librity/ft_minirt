/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 19:52:39 by lpaulo-m         ###   ########.fr       */
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

t_v3d	parse_vector(char *line)
{
	char	**tokens;
	t_v3d	vector;

	tokens = ft_split(line, ',');
	vector.x = ft_atof(tokens[0]);
	vector.y = ft_atof(tokens[1]);
	vector.z = ft_atof(tokens[2]);
	vector.type = VECTOR_TYPE;
	ft_free_strarr(tokens);
	return (vector);
}

t_p3d	parse_point(char *line)
{
	t_p3d	origin;

	origin = parse_vector(line);
	origin.type = POINT_TYPE;
	return (origin);
}

char	*skip_field(char *line)
{
	line = ft_skip_nonwhitespace(line);
	line = ft_skip_whitespace(line);
	return (line);
}
