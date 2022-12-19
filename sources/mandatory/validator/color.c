/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 22:46:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_color(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (is_rgb(line) == false)
		return (false);
	rgb = ft_split(line, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_strarr(rgb);
	if (r < COLOR_MIN || r > COLOR_MAX)
		return (false);
	if (g < COLOR_MIN || g > COLOR_MAX)
		return (false);
	if (b < COLOR_MIN || b > COLOR_MAX)
		return (false);
	return (true);
}

int	is_rgb(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (false);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (false);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (!ft_strchr("\t \n", *line))
		return (false);
	return (true);
}
