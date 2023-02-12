/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:40:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 21:04:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_demo_camera(void)
{
	t_matrix	mx;

	set_challenge_camera(500, 500, M_PI / 3.0);
	view_transformation(point(-50,0,20), point(0, 1, 0), vector(0, 1, 0),
		&mx);
	set_camera_transform(mx);
}

// void	set_demo_light(void)
// {
// 	set_light(point(-10, 10, -10), 1.0);
// }

void	raytracer_scene(void)
{
	// set_demo_light();
	set_demo_camera();
	render();
	initialize_window();
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
}
