/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:45:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 16:58:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	my_putstr_fd(char *str, int fd)
{
	size_t	length;

	if (str == NULL)
		return ;
	length = ft_strlen(str);
	write(fd, &c, length);
}

char	*my_strcpy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

static char	*write_header(int width, int height, char *cursor)
{
	char	*width_s;
	char	*height_s;

	width_s = ft_itoa(width);
	height_s = ft_itoa(height);
	cursor = my_strcpy(cursor, "P3\n");
	cursor = my_strcpy(cursor, width_s);
	cursor = my_strcpy(cursor, " ");
	cursor = my_strcpy(cursor, height_s);
	cursor = my_strcpy(cursor, "\n255\n");
	free(width_s);
	free(height_s);
	return (cursor);
}

static char	*write_color(t_rgb color, char *cursor)
{
	char	*pixel;

	pixel = ft_itoa(color.red);
	cursor = my_strcpy(cursor, pixel);
	cursor = my_strcpy(cursor, " ");
	free(pixel);

	pixel = ft_itoa(color.green);
	cursor = my_strcpy(cursor, pixel);
	cursor = my_strcpy(cursor, " ");
	free(pixel);

	pixel = ft_itoa(color.blue);
	cursor = my_strcpy(cursor, pixel);
	cursor = my_strcpy(cursor, " ");
	free(pixel);
	return (cursor);
}

static void	write_colors(t_mlx_image *image, char *cursor)
{
	int		x;
	int		y;
	t_rgb	color;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			color = mlx_image_get_pixel_rgb(image, x, y);
			cursor = write_color(color, cursor);
			x++;
		}
		cursor = my_strcpy(cursor, "\n");
		y++;
		ft_putstr(".");
	}
}

	// string_buffer = calloc(1, 10000);
	// cursor = string_buffer;
	//
	// cursor = my_strcpy(cursor, "P3\n234 123\n255\n");
	// "P3\n234 123\n255\n                                                                                            "
	// cursor = my_strcpy(cursor, "234 13 123 ");
 	// "P3\n234 123\n255\n234 13 123                                                                                            "

	// - [x] Allocar string buffer grande
	// 		- [x] total = cabecalho + linhas * (colunas * 12 + 1) + 100
	// - [x] Criar função para escrever na buffer e avançar o ponteiro
	// - [x] Escrever o header na buffer
	// - [ ] Escrever os pixies na buffer
	// - [x] Escrever o string buffer no aquivo com um só write.

void	mlx_image_save_ppm(t_mlx_image *image, char *filename)
{
	int		fd;
	size_t	buffer_size;
	char	*string_buffer;
	char	*cursor;

	buffer_size = 150 + image->height * (image->width * 12 + 1) + 100;
	string_buffer = ft_calloc(1, buffer_size);
	cursor = string_buffer;
	cursor = write_header( image->width, image->height, cursor);
	write_colors(image, cursor);

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	write(fd, string_buffer, ft_strlen(string_buffer));
	free(string_buffer);
	close(fd);
}
