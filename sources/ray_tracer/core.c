/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/16 00:35:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_c3i	trace_ray(t_minirt *ctl, t_camera camera, int row, int column)
{
	t_ray	ray;
	t_c3d	cast;
	t_c3i	color;


	ray = get_ray(ctl, camera, row, column);
	cast = cast_ray(ctl, ray);
	color = get_gamma2_pixel(cast);
	return (color);
}

void	generate_image(t_bitmap_image *image,
					t_minirt *ctl,
					t_camera camera)
{
	t_c3i	pixel_color;
	int		row;
	int		column;

	row = ctl->height - 1;
	while (row >= 0)
	{
		ft_putstr("⌛");
		column = 0;
		while (column < ctl->width)
		{
			pixel_color = trace_ray(ctl, camera, row, column);
			set_image_pixel(image, pixel_color, row, column);
			column++;
		}
		row--;
	}
}

void	cleanup_ray_tracer(t_minirt *ctl)
{
	free_spheres(&(ctl->spheres));
}
