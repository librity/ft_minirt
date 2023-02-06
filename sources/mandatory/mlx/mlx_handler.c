/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:18:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/06 11:45:14 by ppaulo-d         ###   ########.fr       */
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

static void	event_hook(void)
{
	mlx_hook(window(), 17, 0, &exit_win, mlx());
	mlx_key_hook(window(), &key_release, mlx());
}

void	mlx_handler(void)
{
	event_hook();
	mlx_loop(mlx());
}
