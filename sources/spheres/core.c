/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/15 00:33:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*new_sphere(t_p3d center, double radius, t_c3d color)
{
	t_sphere	*new;

	new = (t_sphere *)ft_salloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->color = color;
	return (new);
}

void	add_sphere(t_add_sphere p)
{
	t_sphere	*sphere;

	sphere = new_sphere(p.center, p.radius, p.color);
	ft_lst_add(p.spheres, sphere);
}

void	free_spheres(t_list **spheres)
{
	ft_lstclear(spheres, free);
}
