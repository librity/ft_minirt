/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:47:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 00:36:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_ambient_light(t_minirt *ctl, double brightness, t_rgb color_rgb)
{
	ctl->ambient.brightness = brightness;
	ctl->ambient.color_rgb = color_rgb;
	ctl->ambient.color_3d = rgb_to_bright_c3d(brightness, color_rgb);
}
