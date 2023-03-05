/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/26 16:00:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	inspect_camera(void)
{
	t_camera	cam;

	cam = c()->camera;
	printf("=== camera ===\n");
	printf("\torigin: %f %f %f\n", cam.origin.x, cam.origin.y, cam.origin.z);
	printf("\torientation: %f %f %f\n", cam.orientation.x, cam.orientation.y,
		cam.orientation.z);
	printf("\thorz_fov_deg: %f\n", cam.fov_deg);
	printf("\thorz_fov_rad: %f\n", cam.fov_rad);
}

void	set_challenge_camera(int width, int height, double fov_rad)
{
	t_camera	*cam;

	cam = &c()->camera;
	if (cam->initialized)
		return ;
	cam->initialized = true;
	cam->width = width;
	cam->height = height;
	cam->aspect = (double)cam->width / (double)cam->height;
	cam->fov_rad = fov_rad;
	cam->half_view = tan(fov_rad / 2.0);
	if (cam->aspect >= 1.0)
	{
		cam->half_width = cam->half_view;
		cam->half_height = cam->half_view / cam->aspect;
	}
	else
	{
		cam->half_width = cam->half_view * cam->aspect;
		cam->half_height = cam->half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->width;
	mx_set_identity(&cam->transform);
	mlx_image_initialize(&cam->buffer, c()->mlx, cam->width, cam->height);
}

void	set_camera_transform(t_matrix transform)
{
	mx_copy(transform, &c()->camera.transform);
}

void	destroy_camera(void)
{
	t_camera	*cam;

	cam = &c()->camera;
	if (cam->initialized == false)
		return ;
	mlx_image_destroy(&cam->buffer);
	cam->initialized = false;
}
