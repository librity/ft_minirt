/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 18:22:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	*prototype_material(t_scatter_callback scattered)
{
	t_material	*new;

	new = (t_material *)ft_salloc(sizeof(t_material));
	if (new == NULL)
		return (NULL);
	new->scattered = scattered;
	return (new);
}

void	free_materials(t_list **materials)
{
	ft_lstclear(materials, &free);
}
