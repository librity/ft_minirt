/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:08:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	handle_close(int keycode, t_minirt *ctl)
{
	if (keycode == ESC_KEY)
		clean_and_exit(ctl);
	if (keycode == Q_KEY)
		clean_and_exit(ctl);
}

void	handle_navigation(int keycode, t_minirt *ctl)
{
	keycode = keycode;
	ctl = ctl;
	// if (keycode == LEFT_KEY)
	// 	move_left(ctl);
	// if (keycode == RIGHT_KEY)
	// 	move_right(ctl);
}

void	handle_save_to_bitmap(int keycode, t_minirt *ctl)
{
	keycode = keycode;
	ctl = ctl;
	// if (keycode == S_KEY)
	// 	save_to_bitmap(ctl);
}
