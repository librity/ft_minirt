/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/17 23:21:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_c3d	gamma2_correct(t_c3d sampled_color)
{
	sampled_color = vsqrt(sampled_color);
	return (sampled_color);
}

t_rgb	get_gamma2_pixel(t_c3d sampled_color)
{
	sampled_color = gamma2_correct(sampled_color);
	return (color_3d_to_rgb(sampled_color));
}

void	set_image_pixel(t_bitmap_image *image,
						t_rgb color,
						int row,
						int column)
{
	t_bitmap_pixel	*target_pixel;

	target_pixel = &image->pixels[row][column];
	bm_set_pixel(target_pixel, color.red, color.green, color.blue);
}
