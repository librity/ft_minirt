/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/14 13:52:43 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	light_counter(char id)
{
	static int count = 0;

	if (id != 'L')
		return (FALSE);
	count++;
	if (count > 1)
		return (FALSE);
	val_scene()->light = 1;
	return (TRUE);
}

int	validate_light(char *line)
{
	if (light_counter(*line) == FALSE)
		return (FALSE);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_amb_light(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}
