/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:21:09 by lpaulo-m         ###   ########.fr       */
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
