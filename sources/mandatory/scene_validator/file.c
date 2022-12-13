/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/13 10:24:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_scene(char *filename)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(filename, O_RDONLY);
	while (TRUE)
	{
		status = ft_get_next_line(fd, &line);
		if (status == GNL_ERROR)
			die(EC_GNL);
		if (validate_line(line) == FALSE)
			error_validate(line, fd);
		free(line);
		if (status == GNL_FOUND_EOF)
			break ;
	}
}

int	validate_line(char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (TRUE);
	else if (*line == '\n' || !*line)
		return (TRUE);
	if (validate_camera(line) == TRUE)
		return (TRUE);
	if (validate_light(line))
		return (TRUE);
	 if (validate_ambient(line))
		return (TRUE);
	if (validate_sphere(line))
		return (TRUE);
	if (validate_plane(line))
		return (TRUE);
	if (validate_cylinder(line))
		return (TRUE);
	return (FALSE);
}

void	error_validate(char *line, int fd)
{
	free(line);
	close(fd);
	ft_putendl_fd("Error\nminirt: Invalid scene file.", 2);
	exit(1);
}