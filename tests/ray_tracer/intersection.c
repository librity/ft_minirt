/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 20:26:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object		*_sphere;
t_intersection	_intersection;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(intersection_tst)
{
	_sphere = sphere();
	_intersection = intersection(3.5, _sphere);

	mu_assert_double_eq(3.5, _intersection.t);
	mu_check(_sphere == _intersection.object);
}

MU_TEST_SUITE(intersection_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(intersection_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(intersection_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
