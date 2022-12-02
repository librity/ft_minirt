/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 23:13:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	validate_or_die(char *line)
{
	char	*free_me;

	free_me = line;
	line = ft_skip_whitespace(line);
	if (*line == '\0')
		return ;
	if (ft_starts_with(line, "#"))
		return ;
	if (ft_starts_with(line, "A"))
		return (validate_ambient_light(line + 1, free_me));
	if (ft_starts_with(line, "L"))
		return ;
		// return (validate_light(line + 1, free_me));
	if (ft_starts_with(line, "C"))
		return ;
		// return (validate_camera(line + 1, free_me));
	if (ft_starts_with(line, "sp"))
		return ;
		// return (validate_sphere(line + 2, free_me));
	if (ft_starts_with(line, "pl"))
		return ;
		// return (validate_plane(line + 2, free_me));
	if (ft_starts_with(line, "cy"))
		return ;
		// return (validate_cylinder(line + 2, free_me));
	freestr_and_die(free_me, EC_SCENE_IDENTIFIER);
}

void	validate_scene(char *scene_path)
{
	int		fd;
	int		status;
	char	*line;

	fd = open_scene_or_die(scene_path);
	while (true)
	{
		status = ft_get_next_line(fd, &line);
		if (status == GNL_ERROR)
			die(EC_GNL);
		validate_or_die(line);
		free(line);
		if (status == GNL_FOUND_EOF)
			break ;
	}
	close(fd);
}
