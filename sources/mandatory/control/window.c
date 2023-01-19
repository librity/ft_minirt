/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:26:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 19:46:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*window(void)
{
	return (c()->window);
}

void	initialize_window(void)
{
	t_camera	*cam;

	// if (c()->mlx == NULL)
	// 	return ;
	cam = &c()->camera;
	c()->window = mlx_new_window(c()->mlx, cam->width, cam->height, "miniRT");
	if (c()->window == NULL)
		die(MLX_NEW_WINDOW_ERR);
}

void	destroy_window(void)
{
	// if (c()->mlx == NULL)
	// 	return ;
	// if (c()->window == NULL)
	// 	return ;
	mlx_destroy_window(c()->mlx, c()->window);
	c()->window = NULL;
}
