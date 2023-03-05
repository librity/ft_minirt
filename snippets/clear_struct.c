/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:57:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/03/05 19:08:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc clear_struct.c -lm && time ./a.out

#include <strings.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = (unsigned char)0;
		p++;
	}
	return (s);
}

typedef struct s_test
{
	int		intv;
	char	charv;
	void	*voidv;
	char	*strv;
}			t_test;

void	clear_attribution(void)
{
	t_test	test;

	test = (t_test){0};
}

void	clear_bzero(void)
{
	t_test	test;

	bzero(&test, sizeof(t_test));
}

void	clear_ft_bzero(void)
{
	t_test	test;

	ft_bzero(&test, sizeof(t_test));
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i++ < 999999999)
	{
		// clear_attribution();
		// clear_bzero();
		clear_ft_bzero();
	}
	return (0);
}
