/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:31:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 20:39:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	light(void)
{
	return (c()->light);
}

void	set_light(t_p3d origin, double brightness)
{
	c()->light.origin = origin;
	c()->light.brightness = brightness;
	c()->light.color_rgb = color_rgb(255, 255, 255);
	c()->light.color_3d = rgb_to_c3d(c()->light.color_rgb);
}

void	inspect_light(void)
{
	t_light	light;

	light = c()->light;
	printf("=== light ===\n");
	printf("\torigin: %f %f %f\n", light.origin.x, light.origin.y,
		light.origin.z);
	printf("\tbrightness: %f\n", light.brightness);
	printf("\tcolor_rgb: %d %d %d\n", light.color_rgb.red,
		light.color_rgb.green, light.color_rgb.blue);
	printf("\tcolor_3d: %f %f %f\n", light.color_3d.x, light.color_3d.y,
		light.color_3d.z);
}
