/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 13:10:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <stdbool.h>

double			infinity(void);

double			degrees_to_radians(double degrees);

typedef struct s_quadratic
{
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		d_sqrt;
	double		root;
}				t_quadratic;
bool			quadratic(t_quadratic r, double min_translation,
					double max_translation, double *root);

#endif
