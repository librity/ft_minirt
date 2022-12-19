/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:03:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 22:41:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_cy_dimension(char **line);

int	validate_cylinder(char *line)
{
	if (ft_strncmp(line, "cy ", 3) && ft_strncmp(line, "cy\t", 3))
		return (false);
	line = get_next_info(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_cy_dimension(&line) == false)
		return (false);
	line = get_next_info(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}

static int	check_cy_dimension(char **line)
{
	if (ft_isfloat(line) == false)
		return (false);
	*line = get_next_info(*line);
	if (ft_isfloat(line) == false)
		return (false);
	return (true);
}
