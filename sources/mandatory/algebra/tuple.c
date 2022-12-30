/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 11:11:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

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
	return (tuple_3d(0.0, 0.0, 0.0, 0.0));
}

void	inspect_tuple(t_t3d tuple)
{
	printf("TUPLE: %f %f %f, type %f\n", tuple.x, tuple.y, tuple.z, tuple.type);
}

t_t3d	neg(t_t3d tuple)
{
	tuple.x *= -1;
	tuple.y *= -1;
	tuple.z *= -1;
	tuple.type *= -1;
	return (tuple);
}
