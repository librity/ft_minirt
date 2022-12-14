/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:09:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_camera(char *line)
{
	t_p3d	origin;
	t_v3d	orientation;
	double	horz_fov_deg;

	line++;
	line = ft_skip_whitespace(line);
	origin = parse_point(line);
	line = ft_skip_nonwhitespace(line);
	line = ft_skip_whitespace(line);
	orientation = parse_vector(line);
	line = ft_skip_nonwhitespace(line);
	line = ft_skip_whitespace(line);
	horz_fov_deg = ft_atof(line);
	set_camera(origin, orientation, horz_fov_deg);
}
