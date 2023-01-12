#include "../tests.h"

t_world	_world;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(empty_world_tst)
{
	_world = world();

	mu_check(_world.objects == NULL);
	mu_check(_world.light == NULL);
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(empty_world_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
