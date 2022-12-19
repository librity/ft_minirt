/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 22:41:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_sphere(char *line)
{
	if (ft_strncmp(line, "sp ", 3) && ft_strncmp(line, "sp\t", 3))
		return (false);
	line = get_next_info(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (ft_isfloat(&line) == false)
		return (false);
	line = get_next_info(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}
