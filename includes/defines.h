/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 16:16:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 1

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WINDOW_NAME "lpaulo-m's miniRT"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400

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
# define BM_MBT "./bitmaps/mbt_"
# define BM_JULIA "./bitmaps/julia_"
# define BM_JULIA_REAL "real_"
# define BM_JULIA_IMAGINARY "imgry_"
# define BM_NEWTON "./bitmaps/newton_"

# define BM_X "x_"
# define BM_Y "y_"
# define BM_ZOOM "zoom_"
# define BM_ITERATIONS "iter_"
# define BM_INFINITY "inf_"
# define BM_COLOR_MODE "cmode_"
# define BM_DYE "dye_"
# define BM_LERP_FROM "lerpfr_"
# define BM_LERP_TO "lerpto_"
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

#endif
