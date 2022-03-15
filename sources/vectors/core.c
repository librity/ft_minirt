/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 20:48:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	vector(double x, double y, double z)
{
	return (vector_3d(x, y, z));
}

t_v3d	vector_3d(double x, double y, double z)
{
	return ((t_v3d){x, y, z});
}

void	inspect(t_v3d vector)
{
	printf("%f %f %f\n", vector.x, vector.y, vector.z);
}
