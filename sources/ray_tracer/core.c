/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 20:42:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_rgb	trace_ray(t_minirt *ctl, t_camera *camera, int x, int y)
{
	t_ray	ray;
	t_c3d	cast;
	t_rgb	color;


	ray = get_ray(ctl, camera, x, y);
	cast = cast_ray(ctl, ray);
	color = get_gamma2_pixel(cast);
	return (color);
}

void	generate_image(t_minirt *ctl, t_camera *camera)
{
	t_rgb	pixel_color;
	int		x;
	int		y;

	x = ctl->width;
	while (x--)
	{
		ft_putstr("⌛");
		y = ctl->height;
		while (y--)
		{
			pixel_color = trace_ray(ctl, camera, x, y);
			bm_draw_rgb_to_mlx_image(&(camera->buffer), x, y, pixel_color);
		}
	}
}
