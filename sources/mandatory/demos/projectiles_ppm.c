/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 17:49:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// start ← point(0, 1, 0)
// velocity ← normalize(vector(1, 1.8, 0)) * 11.25
// p ← projectile(start, velocity)
// gravity ← vector(0, -0.1, 0)
// wind ← vector(-0.01, 0, 0)
// e ← environment(gravity, wind)
// c ← canvas(900, 550)

/**
 * - [x] Declarar um projetil inicial e ambiente
 * - [x] Rodar a função tick enquanto o y do projetil > 0
 * 		- [x] Para cada posição do projetil, plotar o x,y no buffer da camera (t_mlx_image)
 * - [x] Salvar o buffer como um arquivo "projectile.ppm"
 */
void	projectile_ppm_demo(void)
{
	t_projectile	projectile;
	t_environment	env;
	t_mlx_image		*image;

	image = camera_buffer();

	projectile.position = point(0, 1, 0);
	projectile.velocity = normalize(vector(1, 1.8, 0));
	projectile.velocity = scalar_times(9.0, projectile.velocity);

	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	while (projectile.position.y > 0)
	{
		mlx_image_draw_rgb(image, color_rgb(255, 0, 0),
			projectile.position.x,
			image->height - projectile.position.y);
		projectile = tick(env, projectile);
	}
	mlx_image_save_ppm(image, "projectile.ppm");
}
