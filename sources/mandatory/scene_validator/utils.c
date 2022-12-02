/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 23:11:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	invalid_brightness(char *line)
{
	double	brightness;

	brightness = ft_atof(line);
	if (brightness < BRIGHTNESS_MIN)
		return (true);
	if (brightness > BRIGHTNESS_MAX)
		return (true);
	return (false);
}

bool	invalid_color(char *line)
{
	int	color;

	color = ft_atoi(line);
	if (color < COLOR_MIN)
		return (true);
	if (color > COLOR_MAX)
		return (true);
	return (false);
}

bool	invalid_rgb(char *line)
{
	if (invalid_color(line))
		return (true);
	line = ft_skip_int_commas(line);
	if (invalid_color(line))
		return (true);
	line = ft_skip_int_commas(line);
	if (invalid_color(line))
		return (true);
	line = ft_skip_int_commas(line);
	return (false);
}
