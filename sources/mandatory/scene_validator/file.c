/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/14 13:51:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	error_scene(void);
static void	error_validate(char *line, int fd);

void	validate_scene(char *filename)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(filename, O_RDONLY);
	val_scene_init();
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
	close(fd);
	if (check_scene() == FALSE)
		error_scene();

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

static void	error_validate(char *line, int fd)
{
	free(line);
	close(fd);
	ft_putendl_fd("Error\nminirt: Invalid scene file.", 2);
	exit(1);
}

static void	error_scene(void)
{
	ft_putendl_fd("Error\nminirt: Invalid scene file.", 2);
	exit(1);
}
