/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:00:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*new_sphere(t_new_sphere p)
{
	t_sphere	*new;

	new = (t_sphere *)ft_salloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = p.center;
	new->radius = p.radius;
	new->color = p.color;
	return (new);
}

void	add_sphere(t_minirt *ctl, t_new_sphere p)
{
	t_sphere	*sphere;

	sphere = new_sphere(p);
	ft_lst_add(&(ctl->spheres), sphere);
}

void	free_spheres(t_minirt *ctl)
{
	ft_lst_free(&(ctl->spheres));
}
