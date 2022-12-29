/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 13:43:34 by lpaulo-m         ###   ########.fr       */
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

// Scenario: Colors are (red, green, blue) tuples
//  Given c ← color(-0.5, 0.4, 1.7)
//  Then c.red = -0.5
//  And c.green = 0.4
//  And c.blue = 1.7
MU_TEST(color_tst)
{
	result = color(-0.5, 0.4, 1.7);
	expected = (t_t3d){-0.5, 0.4, 1.7, COLOR_TYPE};
	assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(colors_tst)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(color_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(colors_tst);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
