/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 15:45:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	red_window_demo(void)
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

void	draw_hello_world_to_camera_buffer(void)
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

			mlx_image_draw_c3d(&c()->camera.buffer, color, x, y);
			y++;
		}
		x++;
	}
}

void	hello_world_window_demo(void)
{
	draw_hello_world_to_camera_buffer();
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
}

void	hello_world_ppm_demo(void)
{
	draw_hello_world_to_camera_buffer();
	mlx_image_save_ppm(camera_buffer(), "teste.ppm");
}
