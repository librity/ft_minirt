/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 21:52:28 by lpaulo-m         ###   ########.fr       */
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
# define WINDOW_HEIGHT 600

/******************************************************************************\
 * MATH
\******************************************************************************/

# define TOLERANCE 1e-8

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
	miniRT [scene file path]\n\
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
	BAD_ARGUMENTS = 1,
	GENERIC_RAY_TRACER_ERROR
}	t_errors;

#endif
