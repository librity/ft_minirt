/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:55:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/13 10:27:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ambient_count(char id);

static int	ambient_count(char id)
{
	static int	count = 0;

	if (id != 'A')
		return (FALSE);
	count++;
	if (count > 1)
		return (FALSE);
	return (TRUE);
}

int	validate_ambient(char *line)
{
	if (ambient_count(*line) == FALSE)
		return (FALSE);
	line++;
	line = jump_spaces(line);
	if (check_amb_light(line) == FALSE)
		return (FALSE);
	line = jump_info(line);
	line = jump_spaces(line);
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}

int	check_amb_light(char *line)
{
	char	*hold_line;
	double	ambient_light;

	hold_line = line;
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	ambient_light = ft_atof(hold_line);
	if (ambient_light < BRIGHTNESS_MIN || ambient_light > BRIGHTNESS_MAX)
		return (FALSE);
	return (TRUE);
}
