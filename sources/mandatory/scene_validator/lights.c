/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 23:13:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	validate_ambient_light(char *line, char *free_me)
{
	line = ft_skip_whitespace(line);
	if (invalid_brightness(line))
		freestr_and_die(free_me, EC_AMBIENT_LIGHT_BRIGHTNESS);
	line = ft_skip_float_whitespace(line);
	if (invalid_rgb(line))
		freestr_and_die(free_me, EC_AMBIENT_LIGHT_COLOR);
}
