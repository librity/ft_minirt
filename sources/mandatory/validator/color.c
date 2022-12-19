/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 21:59:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_color(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (is_rgb(line) == FALSE)
		return (FALSE);
	rgb = ft_split(line, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array((void **)rgb);
	if (r < COLOR_MIN || r > COLOR_MAX)
		return (FALSE);
	if (g < COLOR_MIN || g > COLOR_MAX)
		return (FALSE);
	if (b < COLOR_MIN || b > COLOR_MAX)
		return (FALSE);
	return (TRUE);
}

int	is_rgb(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (FALSE);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (FALSE);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (!ft_strchr("\t \n", *line))
		return (FALSE);
	return (TRUE);
}
