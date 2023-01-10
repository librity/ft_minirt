/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:31:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/05 20:43:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	light(void)
{
	return (c()->light);
}

void	set_light(t_p3d origin, double brightness)
{
	c()->light = point_light(origin, brightness, rgb_white());
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
