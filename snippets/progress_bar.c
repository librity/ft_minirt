/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/31 17:45:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang progress_bar.c -o progress_bar && ./progress_bar

#include <unistd.h>
#include <stdio.h>

char *resolve_fill(int progress)
{
	static char	buffer[21];
	char	*str;
	int hashes_count;
	int spaces_count;

	hashes_count = progress / 5;
	spaces_count = 20 - hashes_count;
	str = buffer;
	while (hashes_count--)
	{
		*str = '#';
		str++;
	}
	while (spaces_count--)
	{
		*str = ' ';
		str++;
	}
	buffer[20] = '\0';
	return (buffer);
}

void update_progress(int progress)
{
	printf("\r[%s] %d%%", resolve_fill(progress), progress);
}

int	main(void)
{
	int i;

	i = 0;
	while (i <= 100)
	{
		usleep(100000);
		update_progress(i);
		fflush(stdout);
		i++;
	}
	printf("\n");
	return (0);
}

