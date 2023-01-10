/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:29:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/05 20:43:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	point_light(t_p3d origin, double brightness, t_rgb color_rgb)
{
	t_light	new_light;

	new_light.origin = origin;
	new_light.brightness = brightness;
	new_light.color_rgb = color_rgb;
	new_light.color_3d = rgb_to_c3d(color_rgb);
	new_light.intensity = scalar_times(brightness, new_light.color_3d);
	return (new_light);
}
