/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 00:42:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	handle_destroy(t_minirt *ctl)
{
	clean_and_exit(ctl);
	return (0);
}

int	handle_keypress(int keycode, t_minirt *ctl)
{
	log_keycode(keycode);
	handle_close(keycode, ctl);
	handle_navigation(keycode, ctl);
	handle_save_to_bitmap(keycode, ctl);
	return (0);
}
