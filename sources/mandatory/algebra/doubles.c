/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:43:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

bool	doubles_are_equal(double a, double b)
{
	if (fabs(a - b) < NEAR_ZERO_TOLERANCE)
		return (true);
	return (false);
}

bool	double_near_zero(double a)
{
	return (doubles_are_equal(a, 0.0));
}
