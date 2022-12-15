/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 21:44:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	initialize(int argc, char **argv)
{
	if (argc != 2)
		die(ARGC_ERR);
	initialize_control(argc, argv);
}

void	run(void)
{
	printf("%s\n", scene_path());
	parse_scene();
	inspect_ambient_light();
	inspect_camera();
	inspect_light();
	inspect_objects();
}

void	cleanup(void)
{
	free_lalloc();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run();
	cleanup();
	return (EXIT_SUCCESS);
}
