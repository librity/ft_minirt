/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 19:54:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mlx_demo_img(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			mlx_image_draw_rgb(&c()->camera.buffer, rgb_red(), x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0,
		0);
}

void	mlx_hello_world_img(void)
{
	int		x;
	int		y;
	t_c3d	color;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			color.x = (double) x / width() - 1;
			color.y = (double) y / height() - 1;
			color.z = 0.25;

			mlx_image_draw_rgb(&c()->camera.buffer, c3d_to_rgb(color), x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0,
		0);
}
