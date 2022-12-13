/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:56:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/10 13:23:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	argc(void)
{
	return (c()->argc);
}

void	set_argc(int argc)
{
	c()->argc = argc;
}

char	**argv(void)
{
	return (c()->argv);
}

void	set_argv(char **argv)
{
	c()->argv = argv;
}
