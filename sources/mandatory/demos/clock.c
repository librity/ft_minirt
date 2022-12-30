/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:13:00 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 18:27:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// - [x] Ponto inicial no 12 plano x, y
// - [x] Para cada ponto desenhar no canvas e rotacionar por MY_PI/6 no eixo z
// - [x] Salvar como "clock.ppm"
void clock_hours_ppm_demo(void)
{
	int ticks;
	t_p3d hand;
	t_mlx_image *image;
	t_matrix rotation;

	rotation_z(M_PI / 6.0, &rotation);
	hand = point(0, 50, 0);
	image = camera_buffer();

	ticks = 12;
	while (ticks > 0)
	{
		mlx_image_draw_rgb(image, color_rgb(255, 0, 0),
						   hand.x + image->half_width,
						   hand.y + image->half_height);
		hand = mx_tuple_multiply(rotation, hand);
		ticks--;
	}
	mlx_image_save_ppm(image, "clock.ppm");
}

void clock_sec_ppm_demo(void)
{
	int ticks;
	t_p3d hand;
	t_mlx_image *image;
	t_matrix rotation;

	rotation_z(M_PI / 30, &rotation);
	hand = point(0, 50, 0);
	image = camera_buffer();

	ticks = 60;
	while (ticks > 0)
	{
		if (ticks % 5 == 0)
			mlx_image_draw_rgb(image, color_rgb(255, 255, 255),
							hand.x + image->half_width,
							hand.y + image->half_height);
		else
			mlx_image_draw_rgb(image, color_rgb(255, 0, 0),
						   hand.x + image->half_width,
						   hand.y + image->half_height);
		hand = mx_tuple_multiply(rotation, hand);
		ticks--;
	}
	mlx_image_save_ppm(image, "clock.ppm");
}
