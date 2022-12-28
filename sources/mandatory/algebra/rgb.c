/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:42:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

t_c3d	rgb_to_c3d(t_rgb color_rgb)
{
	t_c3d	c3d;

	c3d.x = (double)color_rgb.red / COLOR_MAX;
	c3d.y = (double)color_rgb.green / COLOR_MAX;
	c3d.z = (double)color_rgb.blue / COLOR_MAX;
	return (c3d);
}

t_c3d	rgb_to_bright_c3d(double brightness, t_rgb color_rgb)
{
	return (scalar_times(brightness, rgb_to_c3d(color_rgb)));
}
