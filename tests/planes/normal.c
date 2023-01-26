/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:12:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:32:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../tests.h"

t_object	*_plane;
t_v3d		v1;
t_v3d		v2;
t_v3d		v3;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(normal_at_tst)
{
	_plane = plane();
	mu_check(_plane->normal_at != NULL);
	mu_check(_plane->normal_at == &plane_normal_at);

	v1 = _plane->normal_at(_plane, point(0, 0, 0));
	v2 = _plane->normal_at(_plane, point(10, 0, -10));
	v3 = _plane->normal_at(_plane, point(-5, 0, 150));
	assert_tuple_eq(vector(0, 1, 0), v1);
	assert_tuple_eq(vector(0, 1, 0), v2);
	assert_tuple_eq(vector(0, 1, 0), v3);
}

MU_TEST_SUITE(plane_normal_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(normal_at_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plane_normal_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
