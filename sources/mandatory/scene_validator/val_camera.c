/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/15 10:22:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	camera_count(char id)
{
	static int count = 0;

	if (id != 'C')
		return (FALSE);
	count++;
	if (count > 1)
		return (FALSE);
	val_scene()->camera = 1;
	return (TRUE);
}

int	validate_camera(char *line)
{
	if (camera_count(*line) == FALSE)
		return (FALSE);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (validate_fov(line) == FALSE)
		return (FALSE);
	line = jump_info(line);
	if ((!ft_strchr(" \n", *line)))
		return (FALSE);
	return (TRUE);
}

int	validate_fov(char *line)
{
	char		*line_hold;
	double		fov;

	line_hold = line;
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	if ((!ft_strchr(" \t\n", *line)) && !*line)
		return (FALSE);
	fov = ft_atof(line_hold);
	if (fov < 0 || fov > 180)
		return (FALSE);
	return (TRUE);
}
