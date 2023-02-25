/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:03:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:41:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	foo;
t_object	*_object;
t_matrix	identity;
t_matrix	trans;
t_material	m;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(default_transformation_tst)
{
	mx_set_identity(&identity);
	_object = create_object();

	mu_check(mxs_are_equal(identity, _object->transform));
}

MU_TEST(set_transformation_tst)
{
	translation(vector(2, 3, 4), &trans);
	_object = create_object();
	set_transform(_object, trans);

	mu_check(mxs_are_equal(trans, _object->transform));
}

MU_TEST(default_material_tst)
{
	_object = create_object();
	m = default_material();

	assert_material_eq(m, _object->material);
}

MU_TEST(assigning_material_tst)
{
	_object = create_object();
	m = default_material();
	m.ambient = 1;
	_object->material = m;

	assert_material_eq(m, _object->material);
}

MU_TEST_SUITE(create_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_transformation_tst);
	MU_RUN_TEST(set_transformation_tst);

	MU_RUN_TEST(default_material_tst);
	MU_RUN_TEST(assigning_material_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(create_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
