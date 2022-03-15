/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:33:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
** Divide the color by the number of samples and gamma-correct for gamma=2.0
*/

t_c3d	scale_and_gamma2_correct(t_c3d sampled_color, double scale)
{
	sampled_color = scalar_times(scale, sampled_color);
	sampled_color = vsqrt(sampled_color);
	return (sampled_color);
}

t_c3i	sample_pixel_color(t_c3d sampled_color, int samples_per_pixel)
{
	t_c3i		color_3i;
	double	scale;

	scale = 1.0 / samples_per_pixel;
	sampled_color = scale_and_gamma2_correct(sampled_color, scale);
	color_3i.red = (int)(256 * ft_clamp_d(sampled_color.x, 0.0, 0.999));
	color_3i.green = (int)(256 * ft_clamp_d(sampled_color.y, 0.0, 0.999));
	color_3i.blue = (int)(256 * ft_clamp_d(sampled_color.z, 0.0, 0.999));
	return (color_3i);
}

void	set_image_pixel(t_bitmap_image *image,
						t_c3i color,
						int row,
						int column)
{
	t_bitmap_pixel	*target_pixel;

	target_pixel = &image->pixels[row][column];
	bm_set_pixel(target_pixel, color.red, color.green, color.blue);
}
