/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:18:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*mlx(void)
{
	return (c()->mlx);
}

void	initialize_mlx(void)
{
	// if (c()->mlx != NULL)
	// 	return ;
	c()->mlx = mlx_init();
	if (c()->mlx == NULL)
		die(MLX_INIT_ERR);
}

void	destroy_mlx(void)
{
	// if (c()->mlx == NULL)
	// 	return ;
	mlx_destroy_display(c()->mlx);
	free(c()->mlx);
	c()->mlx = NULL;
}
