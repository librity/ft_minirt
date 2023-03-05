/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 20:20:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleanup(void)
{
	if (mlx() != NULL)
	{
		mlx_clear_window(mlx(), window());
		destroy_camera();
		destroy_window();
		destroy_mlx();
	}
	free_ray_lalloc();
	free_world_lalloc();
}
