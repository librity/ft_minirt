/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 13:55:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_c3d	result;
t_t3d	expected;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(color_tst)
{
	result = color(-0.5, 0.4, 1.7);
	expected = (t_t3d){-0.5, 0.4, 1.7, COLOR_TYPE};
	assert_tuple_eq(expected, result);
}

MU_TEST(add_tst)
{
	result = add(
		color(0.9, 0.6, 0.75),
		color(0.7, 0.1, 0.25)
	);
	expected = color(1.6, 0.7, 1.0);
	assert_tuple_eq(expected, result);
}

MU_TEST(sub_tst)
{
	result = sub(
		color(0.9, 0.6, 0.75),
		color(0.7, 0.1, 0.25)
	);
	expected = color(0.2, 0.5, 0.5);
	assert_tuple_eq(expected, result);
}

MU_TEST(times_scalar_tst)
{
	result = scalar_times(
		2, color(0.2, 0.3, 0.4)
	);
	expected = color(0.4, 0.6, 0.8);
	assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(colors_tst)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(color_tst);

	MU_RUN_TEST(add_tst);
	MU_RUN_TEST(sub_tst);

	MU_RUN_TEST(times_scalar_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(colors_tst);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
