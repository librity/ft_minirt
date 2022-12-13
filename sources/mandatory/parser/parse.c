/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/13 19:40:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_line(char *line)
{
	if (ft_starts_with(line, "A"))
		return (parse_ambient_light(line));
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
		if (status != GNL_FOUND_LINEBREAK)
			break ;
		parse_line(line);
		free(line);
	}
}
