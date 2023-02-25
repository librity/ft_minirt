/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:13:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_amb_light	ambient_light(void)
{
	return (c()->ambient_light);
}

void	set_ambient_light(double brightness, t_rgb color)
{
	t_c3d	intensity;

	c()->ambient_light.brightness = brightness;
	c()->ambient_light.color_rgb = color;
	intensity = scalar_times(brightness, rgb_to_c3d(color));
	c()->ambient_light.intensity = intensity;
}

void	inspect_ambient_light(void)
{
	t_amb_light	amb;

	amb = c()->ambient_light;
	printf("=== ambient_light ===\n");
	printf("\tbrightness: %f\n", amb.brightness);
	printf("\tcolor_rgb: %d %d %d\n", amb.color_rgb.red, amb.color_rgb.green,
		amb.color_rgb.blue);
	printf("\tintensity: %f %f %f\n", amb.intensity.x, amb.intensity.y,
		amb.intensity.z);
}
