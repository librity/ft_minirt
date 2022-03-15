/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 21:27:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	log_start(t_minirt *ctl)
{
	ft_putstr("\nMaterials: ");
	ft_putnbr(ft_lstsize(ctl->materials));
	ft_putstr("\nSpheres: ");
	ft_putnbr(ft_lstsize(ctl->spheres));
	ft_putstr("\nScaning lines: ");
}

void	log_end(void)
{
	ft_putstr(" Done!");
}

t_c3i	trace_sample_rays(t_minirt *ctl,
								t_camera camera,
								int row,
								int column)
{
	t_ray	ray;
	t_c3d	sample_result;
	t_c3d	sample_color;
	t_c3i	pixel_color;
	int		samples;

	sample_result = (t_c3d){0, 0, 0};
	samples = ctl->samples_per_pixel;
	while (samples--)
	{
		ray = get_sample_ray(ctl, camera, row, column);
		sample_color = cast_ray(ray, ctl->spheres, ctl->max_depth);
		sample_result = add(sample_result, sample_color);
	}
	pixel_color = sample_pixel_color(sample_result, ctl->samples_per_pixel);
	return (pixel_color);
}

void	generate_image(t_bitmap_image *image,
					t_minirt *ctl,
					t_camera camera)
{
	t_c3i	pixel_color;
	int			row;
	int			column;

	row = ctl->height - 1;
	while (row >= 0)
	{
		ft_putstr("⌛");
		column = 0;
		while (column < ctl->width)
		{
			pixel_color = trace_sample_rays(ctl, camera, row, column);
			set_image_pixel(image, pixel_color, row, column);
			column++;
		}
		row--;
	}
}

void	cleanup_ray_tracer(t_minirt *ctl)
{
	free_spheres(&(ctl->spheres));
	free_materials(&(ctl->materials));
}
