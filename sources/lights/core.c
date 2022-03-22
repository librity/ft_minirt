/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:47:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 00:44:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	*new_light(t_new_light p)
{
	t_light	*new;

	new = (t_light *)ft_salloc(sizeof(t_light));
	new->origin = p.origin;
	new->brightness = p.brightness;
	new->color_rgb = p.color_rgb;
	new->color_3d = rgb_to_bright_c3d(p.brightness, p.color_rgb);
	return (new);
}

void	add_light(t_minirt *ctl, t_add_light p)
{
	t_light		*light;

	light = new_light(p);
	ft_lst_add(&(ctl->lights), light);
}

void	free_lights(t_minirt *ctl)
{
	ft_lst_free(&(ctl->lights));
}
