/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:26:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 14:11:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*window(void)
{
	return (c()->window);
}

void	initialize_window(void)
{
	// if (c()->mlx != NULL)
	// 	return ;
	c()->window = mlx_new_window(c()->mlx, c()->width, c()->height, "miniRT");
	if (c()->window == NULL)
		die(MLX_NEW_WINDOW_ERR);
}

void	destroy_window(void)
{
	// if (c()->window == NULL)
	// 	return ;
	mlx_destroy_window(c()->mlx, c()->window);
	c()->window = NULL;
}

int	width(void)
{
	return (c()->width);
}

int	height(void)
{
	return (c()->height);
}

double	aspect_ratio(void)
{
	return (c()->aspect_ratio);
}
