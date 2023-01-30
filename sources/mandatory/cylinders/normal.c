/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:24:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 19:25:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	cylinder_normal_at(t_object *cylinder, t_p3d point)
{
	(void)cylinder;
	return (vector(point.x, 0, point.z));
}
