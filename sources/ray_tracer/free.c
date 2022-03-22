/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:58:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 00:45:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleanup_ctl(t_minirt *ctl)
{
	free_cameras(ctl);
	free_spheres(ctl);
	free_lights(ctl);
}
