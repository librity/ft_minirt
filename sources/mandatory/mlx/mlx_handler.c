/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:18:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/26 16:07:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	exit_win(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	key_release(int key, void *mlx)
{
	(void)mlx;
	if (key == K_ESC)
		exit_win(mlx);
	return (0);
}

static	int	redraw(void)
{
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0, 0);
	return (0);
}

static void	event_hook(void)
{
	mlx_expose_hook(window(), &redraw, mlx());
	mlx_hook(window(), 17, 0, &exit_win, mlx());
	mlx_key_hook(window(), &key_release, mlx());
}

void	mlx_handler(void)
{
	event_hook();
	mlx_loop(mlx());
}
