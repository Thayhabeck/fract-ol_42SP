/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:14:16 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 02:06:07 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arrow_move(int keysys, t_win *win)
{
	if (keysys == UP_KEY)
	{
		win->img.ymin -= 10 * win->img.pass;
		win->img.ymax -= 10 * win->img.pass;
	}
	else if (keysys == DOWN_KEY)
	{
		win->img.ymin += 10 * win->img.pass;
		win->img.ymax += 10 * win->img.pass;
	}	
	else if (keysys == RIGHT_KEY)
	{
		win->img.xmin += 10 * win->img.pass;
		win->img.xmax += 10 * win->img.pass;
	}
	else if (keysys == LEFT_KEY)
	{
		win->img.xmin -= 10 * win->img.pass;
		win->img.xmax -= 10 * win->img.pass;
	}
}

int	handle_input(int keysys, t_win *win)
{
	win->img.pass = (win->img.xmax - win->img.xmin) / WIN_SIDE;
	if (keysys == ESC_KEY || keysys == Q_KEY)
		close_window(win);
	else if (keysys == LEFT_KEY || keysys == UP_KEY || keysys == RIGHT_KEY \
	|| keysys == DOWN_KEY)
		arrow_move(keysys, win);
	else if (keysys == C_KEY || keysys == R_KEY || keysys == G_KEY \
	|| keysys == B_KEY)
		change_pallete(keysys, win);
	else if (keysys == A_KEY || keysys == D_KEY || keysys == W_KEY \
	|| keysys == S_KEY)
		change_range(keysys, win);
	else if (keysys == H_KEY)
		control_log();
	set_image(win);
	return (0);
}

void	follow_mouse(t_win *win, int x, int y)
{
	win->img.pass = (win->img.xmax - win->img.xmin) / WIN_SIDE;
	win->img.xmin += (x - 250) * win->img.pass;
	win->img.xmax += (x - 250) * win->img.pass;
	win->img.ymin += (y - 250) * win->img.pass;
	win->img.ymax += (y - 250) * win->img.pass;
	position_log(x, y);
}

int	zoom(int keysys, int x, int y, t_win *win)
{
	float	range;

	range = win->img.xmax - win->img.xmin;
	if (keysys == SCROLL_UP && win->img.pass > 0.00000000000005)
	{
		win->img.xmin += 0.1 * range;
		win->img.xmax -= 0.1 * range;
		win->img.ymin += 0.1 * range;
		win->img.ymax -= 0.1 * range;
	}
	if (keysys == SCROLL_DOWN)
	{
		win->img.xmin -= 0.1 * range;
		win->img.xmax += 0.1 * range;
		win->img.ymin -= 0.1 * range;
		win->img.ymax += 0.1 * range;
	}
	follow_mouse(win, x, y);
	set_image(win);
	return (0);
}
