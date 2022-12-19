/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 21:59:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_plane(char *line)
{
	if (ft_strncmp(line, "pl ", 3) && ft_strncmp(line, "pl\t", 3))
		return (FALSE);
	line = get_next_info(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}

