/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:13:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 19:43:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_minirt	*c(void)
{
	static t_minirt	_minirt;

	return (&_minirt);
}

void	initialize_control(int argc, char **argv)
{
	c()->debug = false;
	set_argc(argc);
	set_argv(argv);
	set_scene_path(argv[1]);
	c()->camera.initialized = false;
}
