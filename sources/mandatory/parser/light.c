/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:23:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:38:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light(char *line)
{
	t_p3d	origin;
	double	brightness;

	line++;
	line = ft_skip_whitespace(line);
	origin = parse_point(line);
	line = ft_skip_nonwhitespace(line);
	line = ft_skip_whitespace(line);
	brightness = ft_atof(line);
	set_light(origin, brightness);
}
