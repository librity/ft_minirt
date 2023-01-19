/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/17 19:13:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_list	**world_lalloc(void)
{
	return (&(c()->world_lalloc));
}

void	free_world_lalloc(void)
{
	ft_free_lalloc(&(c()->world_lalloc));
}

t_list	**ray_lalloc(void)
{
	return (&(c()->ray_lalloc));
}

void	free_ray_lalloc(void)
{
	ft_free_lalloc(&(c()->ray_lalloc));
}
