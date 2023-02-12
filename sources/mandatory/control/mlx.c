/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:18:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:24:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*mlx(void)
{
	return (c()->mlx);
}

void	initialize_mlx(void)
{
	c()->mlx = mlx_init();
	if (c()->mlx == NULL)
		die(MLX_INIT_ERR);
}

void	destroy_mlx(void)
{
	mlx_destroy_display(c()->mlx);
	free(c()->mlx);
	c()->mlx = NULL;
}
