/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/15 00:37:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	log_start(t_minirt *ctl)
{
	ft_putstr("Spheres: ");
	ft_putnbr(ft_lstsize(ctl->spheres));
	ft_putendl("");
	ft_putstr("Scaning lines: ");
}

void	log_end(void)
{
	ft_putstr(" Done!");
}
