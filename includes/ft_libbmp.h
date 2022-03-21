/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 14:50:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBBMP_H
# define FT_LIBBMP_H

# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define T_MASK 0xFF000000
# define R_MASK 0x00FF0000
# define G_MASK 0x0000FF00
# define B_MASK 0x000000FF

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_rgb
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_rgb;

typedef struct s_trgb
{
	unsigned char	transparency;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_trgb;

int					int_get_t(int color);
int					int_get_r(int color);
int					int_get_g(int color);
int					int_get_b(int color);
int					int_zero_transparency(int color);

int					trgb_chars_to_int(unsigned char transparency,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
int					trgb_to_int(t_trgb color);

t_rgb				color_rgb(unsigned char red, unsigned char green,
						unsigned char blue);
int					rgb_to_int(t_rgb color);
int					rgb_chars_to_int(unsigned char red, unsigned char green,
						unsigned char blue);

t_trgb				int_to_trgb(int color);
t_rgb				int_to_rgb(int color);

/******************************************************************************\
 * BITMAP
\******************************************************************************/

extern void			*bm_initialize(int width, int height);

extern void			bm_draw(void *bitmap, t_rgb color, int x, int y);

extern void			bm_save(void *bitmap, char *filename);

extern void			bm_free(void *bitmap);

/******************************************************************************\
 * MLX
\******************************************************************************/

typedef struct s_mlx_image
{
	void			*mlx;
	void			*img;
	char			*data;

	int				width;
	int				height;
	int				half_width;
	int				half_height;

	int				line_length;
	int				bits_per_pixel;
	int				endian;
}					t_mlx_image;

void				mlx_image_initialize(t_mlx_image *image, void *mlx,
						int width, int height);

void				mlx_image_draw_int(t_mlx_image *image, int color,
						int x, int y);
void				mlx_image_draw_rgb(t_mlx_image *image, t_rgb color,
						int x, int y);

int					mlx_image_get_pixel_int(t_mlx_image *image, int x, int y);

void				mlx_image_save_bm(t_mlx_image *image, char *filename);

void				mlx_image_destroy(t_mlx_image *image);

#endif
