/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:55:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:03:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_c3d	color_3d(double red, double green, double blue)
{
	return ((t_c3d){red, green, blue, COLOR_TYPE});
}

t_rgb	c3d_to_rgb(t_c3d color_3d)
{
	t_rgb	rgb;

	rgb.red = (int)(COLOR_MAX * color_3d.x);
	rgb.green = (int)(COLOR_MAX * color_3d.y);
	rgb.blue = (int)(COLOR_MAX * color_3d.z);
	return (rgb);
}
