/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:47:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 18:56:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../tests.h"

t_ray	result;
t_t3d	expected;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(rays_tst)
{
	result = ray(point(1, 2, 3), vector(4, 5, 6));

	expected = point(1, 2, 3);
	assert_tuple_eq(expected, result.origin);

	expected = vector(4, 5, 6);
	assert_tuple_eq(expected, result.direction);
}

MU_TEST_SUITE(rays_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(rays_tst);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(rays_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
