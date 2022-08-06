/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 01:15:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	die(t_errors code)
{
	print_error(code);
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr, t_errors code)
{
	if (ptr == NULL)
		die(code);
}

void	help_and_die(void)
{
	ft_putstr(HELP_MSG);
	exit(EXIT_FAILURE);
}

void	freestr_and_die(char *free_me, t_errors code)
{
	free(free_me);
	die(code);
}
