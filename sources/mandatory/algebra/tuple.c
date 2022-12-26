/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 19:19:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_t3d	tuple(double x, double y, double z, double type)
{
	return (tuple_3d(x, y, z, type));
}

t_t3d	tuple_3d(double x, double y, double z, double type)
{
	return ((t_t3d){x, y, z, type});
}

t_t3d	null_tuple(void)
{
	return (tuple_3d(0.0, 0.0, 0.0, NULL_TYPE));
}

void	inspect_tuple(t_t3d tuple)
{
	printf("TUPLE: %f %f %f, type %f\n", tuple.x, tuple.y, tuple.z, tuple.type);
}
