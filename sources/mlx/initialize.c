/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:28:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 00:48:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	initialize_mlx_core(t_minirt *ctl)
{
	log_msg(MLX_MSG);
	ctl->mlx = mlx_init();
	die_if_null(ctl->mlx);
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_window(t_minirt *ctl)
{
	log_msg(WINDOW_MSG);
	ctl->window = mlx_new_window(ctl->mlx,
			ctl->width,
			ctl->height,
			WINDOW_NAME);
	die_if_null(ctl->window);
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_buffer(t_minirt *ctl)
{
	log_msg(BUFFER_MSG);
	bm_initialize_mlx_image(&(ctl->buffer), ctl->mlx, ctl->width, ctl->height);
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_hooks(t_minirt *ctl)
{
	log_msg(HOOKS_MSG);
	mlx_hook(ctl->window, DestroyNotify, ButtonPressMask, handle_destroy, ctl);
	mlx_hook(ctl->window, KeyPress, KeyPressMask, handle_keypress, ctl);
	log_endl(SUCCESS_MSG);
}

void	initialize_mlx(t_minirt *ctl)
{
	initialize_mlx_core(ctl);
	initialize_mlx_window(ctl);
	initialize_mlx_buffer(ctl);
	initialize_mlx_hooks(ctl);
}
