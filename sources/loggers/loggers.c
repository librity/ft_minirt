/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 00:56:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	log_keycode(int keycode)
{
	if (VERBOSE)
		ft_printf(" => Key pressed: %i\n", keycode);
}

void	log_camera(int camera_code)
{
	if (VERBOSE)
		ft_printf(" => Camera: %i\n", camera_code);
}

void	log_scene(t_minirt *ctl)
{
	if (VERBOSE)
	{
		ft_printf(" => Lights: %i\n", ft_lstsize(ctl->lights));
		ft_printf(" => Cameras: %i\n", ft_lstsize(ctl->cameras));
		ft_printf(" => Spheres: %i\n", ft_lstsize(ctl->spheres));
		ft_printf(" => Planes: %i\n", ft_lstsize(ctl->planes));
		ft_printf(" => Cylinders: %i\n", ft_lstsize(ctl->cylinders));
	}
}
