/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/12 19:54:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	validate_line(char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (true);
	else if (*line == '\n' || !*line)
		return (true);
	if (validate_camera(line) == true)
		return (true);
	if (validate_light(line))
		return (true);
	if (validate_ambient(line))
		return (true);
	if (validate_sphere(line))
		return (true);
	if (validate_plane(line))
		return (true);
	if (validate_cylinder(line))
		return (true);
	return (false);
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

void	validate_scene(void)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(scene_path(), O_RDONLY);
	val_scene_init();
	while (true)
	{
		status = ft_get_next_line(fd, &line);
		if (status == FT_GNL_ERROR)
			die(GET_LINE_ERR);
		if (validate_line(line) == false)
			error_validate(line, fd);
		free(line);
		if (status == FT_GNL_FOUND_EOF)
			break ;
	}
	close(fd);
	if (check_scene() == false)
		error_scene();
}
