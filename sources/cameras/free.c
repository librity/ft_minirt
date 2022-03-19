/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:45:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	free_camera(void *free_me)
{
	t_camera	*destroy_my_buffer;

	destroy_my_buffer = free_me;
	bm_destroy_mlx_image(&(destroy_my_buffer->buffer));
	free(free_me);
}

void	free_cameras(t_minirt *ctl)
{
	ft_lstclear(&(ctl->cameras), free_camera);
}
