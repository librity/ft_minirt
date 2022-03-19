/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 23:38:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	initialize_ctl(t_minirt *ctl)
{
	ctl->width = WINDOW_WIDTH;
	ctl->height = WINDOW_HEIGHT;
	ctl->aspect_ratio = (float)ctl->width / (float)ctl->height;
	ctl->cameras = NULL;
	ctl->lights = NULL;
	ctl->spheres = NULL;
	ctl->planes = NULL;
	ctl->cylinders = NULL;
}
