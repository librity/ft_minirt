/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:30:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_t3d	tuple(double x, double y, double z, t_t3d_type type)
{
	return ((t_t3d){x, y, z, type});
}

void	inspect_tuple(t_t3d tuple)
{
	printf("TUPLE: %f %f %f, type %d\n", tuple.x, tuple.y, tuple.z, tuple.type);
}
