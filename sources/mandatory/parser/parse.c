/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:12:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_line(char *line)
{
	line = ft_skip_whitespace(line);
	if (*line == '\0')
		return ;
	if (ft_starts_with(line, "A"))
		return (parse_ambient_light(line));
	if (ft_starts_with(line, "C"))
		return (parse_camera(line));
	// ...
	// free(line);
	// die(GENRIC_ERR);
}

void	parse_scene(void)
{
	int		fd;
	int		status;
	char	*line;

	fd = open_or_die(scene_path());
	while (true)
	{
		status = ft_gnl(fd, &line);
		if (status == FT_GNL_ERROR)
			die(GET_LINE_ERR);
		parse_line(line);
		free(line);
		if (status == FT_GNL_FOUND_EOF)
			break ;
	}
	close_or_die(fd);
}
