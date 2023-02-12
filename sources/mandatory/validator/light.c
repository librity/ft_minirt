/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/12 19:54:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	light_counter(char id)
{
	static int	count;

	count = 0;
	if (id != 'L')
		return (false);
	count++;
	if (count > 1)
		return (false);
	val_scene()->light = 1;
	return (true);
}

int	validate_light(char *line)
{
	if (light_counter(*line) == false)
		return (false);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_amb_light(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}
