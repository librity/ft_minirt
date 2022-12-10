/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/10 08:25:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
		printf("%s\n", line);
		free(line);
	}
}
