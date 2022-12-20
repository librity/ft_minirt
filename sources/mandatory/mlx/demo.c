/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 19:09:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mlx_demo_img(void)
{
	int x;
	int	y;

	x = 0;
	while (x < c()->width)
	{
		y = 0;
		while (y < c()->height)
		{
			// Resolve ray tracer color
			mlx_image_draw_rgb(&c()->camera.buffer, rgb_red(), x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(c()->mlx, c()->window, c()->camera.buffer.img, 0, 0);
}
