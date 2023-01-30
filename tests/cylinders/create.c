/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:31:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 20:12:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_cyl;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(min_max_tst)
{
	_cyl = cylinder();

	mu_assert_double_eq(-DBL_MAX, _cyl->minimum);
	mu_assert_double_eq(DBL_MAX, _cyl->maximum);
}

MU_TEST_SUITE(create_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(min_max_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(create_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
