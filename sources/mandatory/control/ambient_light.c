/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/13 19:38:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_amb_light	ambient_light(void)
{
	return (c()->ambient);
}

void	set_ambient_light(double brightness, t_rgb color)
{
	c()->ambient.brightness = brightness;
	c()->ambient.color_rgb = color;
	c()->ambient.color_3d = rgb_to_c3d(c()->ambient.color_rgb);
}
