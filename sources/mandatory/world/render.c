/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:45:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 18:54:44 by lpaulo-m         ###   ########.fr       */
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
		ft_putchar('.');
		x++;
	}
	ft_endl();
}

static void	set_demo_camera(void)
{
	t_matrix	mx;

	set_challenge_camera(200, 200, M_PI / 3.0);
	view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0),
		&mx);
	set_camera_transform(mx);
}

void	render_to_window(void)
{
	set_demo_camera();
	render();
	initialize_window();
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
}
