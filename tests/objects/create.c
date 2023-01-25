/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:03:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 20:22:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	foo;
t_object	*_object;
t_matrix	identity;
t_matrix	trans;

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

MU_TEST_SUITE(create_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_transformation_tst);
	MU_RUN_TEST(set_transformation_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(create_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
