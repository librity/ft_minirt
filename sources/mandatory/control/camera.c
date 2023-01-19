/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/19 20:21:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_camera	camera(void)
{
	return (c()->camera);
}

t_mlx_image	*camera_buffer(void)
{
	return (&c()->camera.buffer);
}

void	set_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg)
{
	t_camera	*cam;

	// t_p3d		ll_corner;
	cam = &(c()->camera);
	cam->origin = origin;
	cam->orientation = orientation;
	cam->fov_deg = horz_fov_deg;
	cam->fov_rad = degrees_to_radians(horz_fov_deg);
	// cam->view_width = 2.0 * tan(cam->horz_fov_rad / 2.0);
	// cam->view_height = cam->view_width / c()->aspect_ratio;
	// cam->horizontal = scalar_times(cam->view_width,
	// 		vector(cam->orientation.x, 0, 0));
	// cam->vertical = scalar_times(cam->view_height,
	// 		vector(0, cam->orientation.y, 0));
	// ll_corner = sub(cam->origin, scalar_div(2.0, cam->horizontal));
	// ll_corner = sub(ll_corner, scalar_div(2.0, cam->vertical));
	// ll_corner = sub(ll_corner, vector(0, 0, cam->orientation.z));
	// cam->ll_corner = ll_corner;
}

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

int	width(void)
{
	return (c()->camera.width);
}

int	height(void)
{
	return (c()->camera.height);
}

double	aspect_ratio(void)
{
	return (c()->camera.aspect);
}
