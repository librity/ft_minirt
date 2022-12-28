/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:31:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_projectile	projectile;
t_environment	env;
t_projectile	result;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(tick_1_tst)
{
	projectile.position = point(0, 0, 0);
	projectile.velocity = vector(23, 45, 0);

	env.gravity = vector(0, -0.5, 0);
	env.wind = vector(2, 0, -0.6);

	result = tick(env, projectile);
	assert_tuple_eq(point(23, 45, 0), result.position);
	assert_tuple_eq(vector(25, 44.5, -0.6), result.velocity);
}

MU_TEST(tick_2_tst)
{
	projectile.position = point(0, 1, 0);
	// projectile.velocity = normalize(vector(1, 1, 0));
	projectile.velocity = vector(1, 1, 0);

	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	result = tick(env, projectile);
	assert_tuple_eq(point(1, 2, 0), result.position);
	assert_tuple_eq(vector(0.99, 0.9, 0), result.velocity);
}

MU_TEST_SUITE(projectiles_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tick_1_tst);
	MU_RUN_TEST(tick_2_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(projectiles_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
