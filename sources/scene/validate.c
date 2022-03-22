/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 01:43:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	validate_line(char *line)
{
	line = ft_skip_whitespace(line);
	if (ft_starts_with(line, "#"))
		return ;
	// if (ft_starts_with(line, "A"))
	// 	return (validate_ambient_light(line));
	// if (ft_starts_with(line, "L"))
	// 	return (validate_light(line));
	// if (ft_starts_with(line, "C"))
	// 	return (validate_camera(line));
	// if (ft_starts_with(line, "sp"))
	// 	return (validate_sphere(line));
	// if (ft_starts_with(line, "pl"))
	// 	return (validate_plane(line));
	// if (ft_starts_with(line, "cy"))
	// 	return (validate_cylinder(line));
	die(EC_GENERIC);
}

void	validate_scene(char *scene_path)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		die(EC_GENERIC);
	while (true)
	{
		status = ft_get_next_line(fd, &line);
		if (status == GNL_ERROR)
			die(EC_GENERIC);
		validate_line(line);
		free(line);
		if (status == GNL_FOUND_EOF)
			break ;
	}
	close(fd);
}
