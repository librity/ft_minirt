/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:23:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/17 19:53:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_matrix mx_result;
t_matrix mx_expected;
t_p3d		_from;
t_p3d		_to;
t_v3d		_up;

void test_setup(void)
{
	c()->objects = NULL;
}
void test_teardown(void)
{
	free_world_lalloc();
	c()->objects = NULL;
}

MU_TEST(transf_default_orientation_tst)
{
	_from = point(0, 0, 0);
	_to = point(0, 0, -1);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	mx_set_identity(&mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_positive_z_tst)
{
	_from = point(0, 0, 0);
	_to = point(0, 0, 1);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	scaling(vector(-1, 1, -1), &mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_moves_world_tst)
{
	_from = point(0, 0, 8);
	_to = point(0, 0, 0);
	_up = vector(0, 1, 0);
	view_transformation(_from, _to, _up, &mx_result);
	translation(vector(0, 0, -8), &mx_expected);

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST(transf_arbitrary_tst)
{
	_from = point(1.0, 3.0, 2.0);
	_to = point(4.0, -2.0, 8.0);
	_up = vector(1.0, 1.0, 0.0);
	view_transformation(_from, _to, _up, &mx_result);
	mx_set(&mx_expected, (t_mx_set){
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0.00000, 0.00000, 0.00000, 1.00000
	});

	mu_check(mxs_are_equal(mx_expected, mx_result));
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(transf_default_orientation_tst);
	MU_RUN_TEST(transf_positive_z_tst);
	MU_RUN_TEST(transf_moves_world_tst);
	MU_RUN_TEST(transf_arbitrary_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
