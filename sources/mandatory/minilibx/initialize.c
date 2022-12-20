/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:18:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 18:24:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	initialize_minilibx(void)
{
	c()->mlx = mlx_init();
	if (c()->mlx == NULL)
		die(GENRIC_ERR);
	c()->window = mlx_new_window(c()->mlx, c()->width, c()->height, "miniRT");
	if (c()->window == NULL)
		die(GENRIC_ERR);
	mlx_clear_window(c()->mlx, c()->window);
}
