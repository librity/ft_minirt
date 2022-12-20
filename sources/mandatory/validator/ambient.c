/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:55:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 22:41:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	ambient_count(char id);

static int	ambient_count(char id)
{
	static int	count = 0;

	if (id != 'A')
		return (false);
	count++;
	if (count > 1)
		return (false);
	val_scene()->ambient_light = 1;
	return (true);
}

int	validate_ambient(char *line)
{
	if (ambient_count(*line) == false)
		return (false);
	line++;
	line = jump_spaces(line);
	if (check_amb_light(line) == false)
		return (false);
	line = jump_info(line);
	line = jump_spaces(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}

int	check_amb_light(char *line)
{
	char	*hold_line;
	double	ambient_light;

	hold_line = line;
	if (ft_isfloat(&line) == false)
		return (false);
	ambient_light = ft_atof(hold_line);
	if (ambient_light < BRIGHTNESS_MIN || ambient_light > BRIGHTNESS_MAX)
		return (false);
	return (true);
}
