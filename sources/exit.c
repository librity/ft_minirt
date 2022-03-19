/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:48:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	clean(t_minirt *ctl)
{
	cleanup_ray_tracer(ctl);
	mlx_destroy_window(ctl->mlx, ctl->window);
	mlx_destroy_display(ctl->mlx);
	free(ctl->mlx);
	ft_putendl(EXIT_MSG);
}

void	clean_and_exit(t_minirt *ctl)
{
	clean(ctl);
	exit(EXIT_SUCCESS);
}
