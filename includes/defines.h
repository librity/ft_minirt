/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 17:15:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 1

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WINDOW_NAME "lpaulo-m's miniRT"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400

/******************************************************************************\
 * MATH
\******************************************************************************/

# define NEAR_ZERO_TOLERANCE 1e-8

/******************************************************************************\
 * QUIT
\******************************************************************************/

# define ESC_KEY 65307
# define Q_KEY 113

/******************************************************************************\
 * CAMERAS
\******************************************************************************/

# define LEFT_KEY 65361
# define RIGHT_KEY 65363

/******************************************************************************\
 * SAVE TO BITMAP
\******************************************************************************/

# define S_KEY 115

# define BM_SEPARATOR "_"

# define BM_DIRECTORY "./bitmaps/"
# define BM_CAMERA "camera_"
# define BM_EXTENSION ".bmp"

/******************************************************************************\
 * MESSAGES
\******************************************************************************/

# define HELP_MSG "Welcome to lpaulo-m's miniRT!\n\
\n\
USAGE:\n\
	miniRT ./path/to/scene.rt\n\
\n\
EXAMPLES:\n\
	miniRT scenes/demo.rt\n\
\n\
"

# define WELCOME_MSG "=== lpaulo-m presents: miniRT ===\n\
\n\
    CONTROLS:\n\
	Esc or q: Exits program\n\
	Left and Right Arrows: Switch camera\n\
	s: Saves viewport to bitmap\n\
"

# define EXIT_MSG "=== That's all folks! ==="

# define MLX_MSG " => Initializing minilibx..."
# define WINDOW_MSG " => Creating window..."
# define BUFFER_MSG " => Initializing image buffer..."
# define HOOKS_MSG " => Adding hooks..."
# define TRACING_MSG " => Tracing lines: "

# define BM_MSG " => Saving viewport to bitmap file: "

# define SUCCESS_MSG " DONE"

/******************************************************************************\
 * ERRORS
\******************************************************************************/

typedef enum e_errors
{
	EC_MLX_INIT = 1,
	EC_MLX_WINDOW,
	EC_GENERIC
}	t_errors;

# define EKEYEXPIRED 127
# define EKEYEXPIRED_STR "127\n"

# define ERR_INDICATOR "ERROR"

/******************************************************************************\
 * COLORS
\******************************************************************************/

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define BK "\033[0;30m"
# define R "\033[0;31m"
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define B "\033[0;34m"
# define P "\033[0;35m"
# define C "\033[0;36m"
# define W "\033[0;37m"

/* Bold */
# define BKB "\033[1;30m"
# define RB "\033[1;31m"
# define GB "\033[1;32m"
# define YB "\033[1;33m"
# define BB "\033[1;34m"
# define PB "\033[1;35m"
# define CB "\033[1;36m"
# define WB "\033[1;37m"

/* Reset Color */
# define RC "\033[0m"

#endif
