/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 19:14:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	initialize_view(t_minirt *ctl)
{
	ctl->width = WINDOW_WIDTH;
	ctl->height = WINDOW_HEIGHT;
	ctl->aspect_ratio = (double)ctl->width / (double)ctl->height;
}

static void	initialize_ambient_light(t_minirt *ctl)
{
	set_ambient_light(
		ctl,
		1.0,
		color_rgb(255, 255, 255)
		);
}

static void	initialize_lists(t_minirt *ctl)
{
	ctl->cameras = NULL;
	ctl->lights = NULL;
	ctl->spheres = NULL;
	ctl->planes = NULL;
	ctl->cylinders = NULL;
}

void	initialize_ctl(t_minirt *ctl)
{
	initialize_view(ctl);
	initialize_ambient_light(ctl);
	initialize_lists(ctl);
}
