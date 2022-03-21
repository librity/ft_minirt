/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 22:45:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	*build_filename(t_camera *camera)
{
	char	*filename;

	filename = ft_strdup(BM_DIRECTORY);
	filename = ft_strjoin_free(filename, BM_CAMERA);
	filename = ft_strjoin_free_free(filename, ft_itoa(camera->number));
	filename = ft_strjoin_free(filename, BM_EXTENSION);
	return (filename);
}

void	save_camera_buffer(t_camera *camera)
{
	char	*filename;

	filename = build_filename(camera);
	log_msg(BM_MSG);
	bm_save_mlx_image(&(camera->buffer), filename);
	log_msg(filename);
	free(filename);
	log_endl(SUCCESS_MSG);
}
