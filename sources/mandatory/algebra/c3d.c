/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:55:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/10 20:12:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

t_c3d	color(double red, double green, double blue)
{
	return (color_3d(red, green, blue));
}

t_c3d	color_3d(double red, double green, double blue)
{
	return ((t_c3d){red, green, blue, COLOR_TYPE});
}

static	unsigned char	color_to_char(double color)
{
	if (color >= 1.0)
		return (COLOR_MAX);
	if (color <= 0.0)
		return (COLOR_MIN);
	return ((unsigned char)(COLOR_MAX * color));
}

t_rgb	c3d_to_rgb(t_c3d color_3d)
{
	t_rgb	rgb;

	rgb.red = color_to_char(color_3d.x);
	rgb.green = color_to_char(color_3d.y);
	rgb.blue = color_to_char(color_3d.z);
	return (rgb);
}

void	mlx_image_draw_c3d(t_mlx_image *image, t_c3d color, int x, int y)
{
	t_rgb	color_rgb;

	color_rgb = c3d_to_rgb(color);
	mlx_image_draw_rgb(image, color_rgb, x, y);
}
