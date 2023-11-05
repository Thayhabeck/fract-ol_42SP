/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:42:39 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 23:49:07 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/local/include/mlx.h"
# include "../libft/libft.h"
# include "./structs.h"
# include "./defines.h"
# include <stdlib.h>
# include <math.h>

/******************************************************************************\
 * FRACTOL.C
\******************************************************************************/

void	print_image(t_img *img);
void	set_image(t_win *win);
int		set_window(t_win *win);
double	convert_params(char *nbr);
void	set_params(char **argv, t_win *win);

/******************************************************************************\
 * FRACTOL_UTILS.C
\******************************************************************************/

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		close_window(t_win *win);
void	change_pallete(int keysys, t_win *win);
void	change_range(int keysys, t_win *win);

/******************************************************************************\
 * ARGUMENTS.C
\******************************************************************************/

void	args_help(void);
int		check_julia(char *nbr);
int		arg_verify(int argc, char **argv, t_win	*win);

/******************************************************************************\
 * MANDELBROT.C
\******************************************************************************/

int		mandelbrot(double x, double y, t_img *img);

/******************************************************************************\
 * JULIA.C
\******************************************************************************/

int		julia(double x, double y, t_img *img);

/******************************************************************************\
 * STARJULIA.C
\******************************************************************************/

int		starjulia(double x, double y, t_img *img);

/******************************************************************************\
 * COLOR.C
\******************************************************************************/

int		bernstein_color(int iteration, t_img *img);
void	set_color_bernstein(double x, double y, int iteration, t_img *img);
void	set_color_pallete(double x, double y, int iteration, t_img *img);
void	set_color(double x, double y, int i, t_img *img);

/******************************************************************************\
 * COLOR_RGB.C
\******************************************************************************/

void	set_color_rgb(double x, double y, int i, t_img *img);
int		set_color_blue(int iteration, t_img *img);
int		set_color_red(int iteration, t_img *img);
int		set_color_green(int iteration, t_img *img);

/******************************************************************************\
 * HOOKS.C
\******************************************************************************/

void	arrow_move(int keysys, t_win *win);
int		handle_input(int keysys, t_win *win);
void	follow_mouse(t_win *win, int x, int y);
int		zoom(int keysys, int x, int y, t_win *win);

/******************************************************************************\
 * LOGS.C
\******************************************************************************/

void	control_log(void);
void	interation_log(int i, int r);
void	color_log(int code);
void	position_log(int x, int y);

#endif
