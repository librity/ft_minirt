/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:18:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/18 22:41:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_val_scene	*val_scene(void)
{
	static t_val_scene	val_scene;

	return (&val_scene);
}

void	val_scene_init(void)
{
	val_scene()->ambient_light = 0;
	val_scene()->light = 0;
	val_scene()->camera = 0;
}

int	check_scene(void)
{
	if (val_scene()->ambient_light && val_scene()->light && val_scene()->camera)
		return (true);
	return (false);
}
