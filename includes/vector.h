/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:49:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>
# include <math.h>

typedef struct	s_vector_3d
{
	double	x;
	double	y;
	double	z;
}				t_vector_3d;

typedef t_vector_3d	t_point_3d;

t_vector_3d		vector(double x, double y, double z);
t_vector_3d		vector_3d(double x, double y, double z);

void			inspect(t_vector_3d vector);

#endif
