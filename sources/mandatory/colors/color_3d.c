/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 00:36:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	color_3d(double red, double green, double blue)
{
	return ((t_c3d){red, green, blue});
}

t_rgb	c3d_to_rgb(t_c3d color_3d)
{
	t_rgb	rgb;

	rgb.red = (int)(255.999 * color_3d.x);
	rgb.green = (int)(255.999 * color_3d.y);
	rgb.blue = (int)(255.999 * color_3d.z);
	return (rgb);
}

t_c3d	rgb_to_c3d(t_rgb color_rgb)
{
	t_c3d	c3d;

	c3d.x = (double)color_rgb.red / 255.999;
	c3d.y = (double)color_rgb.green / 255.999;
	c3d.z = (double)color_rgb.blue / 255.999;
	return (c3d);
}

t_c3d	rgb_to_bright_c3d(double brightness, t_rgb color_rgb)
{
	return (scalar_times(brightness, rgb_to_c3d(color_rgb)));
}
