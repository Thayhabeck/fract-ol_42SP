/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:08:28 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 17:53:33 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WIN_TITLE "thabeck-'s fract-ol project"
# define WIN_SIDE 500
# define MLX_ERROR 1
# define MAX_ITER 50

/******************************************************************************\
 * FRACTALS
\******************************************************************************/

# define MANDELBROT_CODE 1
# define JULIA_CODE 2
# define STARJULIA_CODE 3

# define MANDELBROT_ARG "mandelbrot"
# define JULIA_ARG "julia"
# define STARJULIA_ARG "starjulia"

/******************************************************************************\
 * EXIT KEYS
\******************************************************************************/

# define ESC_KEY 65307
# define Q_KEY 113

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define C_KEY 99
# define R_KEY 114
# define G_KEY 103
# define B_KEY 98
# define D_KEY 100
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define H_KEY 104

/******************************************************************************\
 * COLOR MODE
\******************************************************************************/

# define BERNSTEIN_CODE 1
# define PALLETE_CODE 2
# define RED_CODE 3
# define GREEN_CODE 4
# define BLUE_CODE 5

# define PALLETE_MODE "Beach Pallete"
# define BERNSTEIN_MODE "Bernstein Polynomials"
# define RED_MODE "Red pallete"
# define GREEN_MODE "Green pallete"
# define BLUE_MODE "Blue pallete"

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define DYE1 0x00FF6F69
# define DYE2 0x00FFCC5C
# define DYE3 0x00FFEEAD
# define DYE4 0x0096CEB4
# define DYE5 0x00F2AE72

# define BLUE1 0x003333FF
# define BLUE2 0x000000FF
# define BLUE3 0x000000CC
# define BLUE4 0x00000099
# define BLUE5 0x00000066

# define GREEN1 0x0033FF33
# define GREEN2 0x0000FF00
# define GREEN3 0x0000CC00
# define GREEN4 0x00009900
# define GREEN5 0x00006600

# define RED1 0x00FF3333
# define RED2 0x00FF0000
# define RED3 0x00CC0000
# define RED4 0x00990000
# define RED5 0x00660000

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

#endif
