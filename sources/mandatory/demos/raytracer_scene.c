/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:40:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 16:39:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_demo_camera(void)
{
	t_matrix	mx;

	set_challenge_camera(200, 200, M_PI / 3.0);
	view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0),
			&mx);
	set_camera_transform(mx);
}

void	raytracer_scene(void)
{
	set_demo_camera();
	render();
	initialize_window();
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
}
