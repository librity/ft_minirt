/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:45:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 20:57:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	render(void)
{
	int		x;
	int		y;
	t_ray	px_ray;
	t_c3d	px_color;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			px_ray = ray_for_pixel(x, y);
			px_color = color_at(px_ray);
			mlx_image_draw_c3d(camera_buffer(), px_color, x, y);
			y++;
		}
		printf(".");
		x++;
	}
}
