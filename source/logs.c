/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:08:38 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/17 01:36:28 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	control_log(void)
{
	ft_putstr_fd("\n== THABECK'S FRACTOL CONTROL ==\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Screen Control:\n", 1);
	ft_putstr_fd("Arrow Keys - screen navigate \n", 1);
	ft_putstr_fd("Mouse Wheel - zoom control\n", 1);
	ft_putstr_fd("H Key - Print Control tips\n", 1);
	ft_putstr_fd("Q Key - Close window\n", 1);
	ft_putstr_fd("ESC Key - Close window\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Color Control: \n", 1);
	ft_putstr_fd("C Key - Change color algorithm\n", 1);
	ft_putstr_fd("R Key - Set monochromatic RED\n", 1);
	ft_putstr_fd("G Key - Set monochromatic GREEN\n", 1);
	ft_putstr_fd("B Key - Set monochromatic BLUE\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Image Control: \n", 1);
	ft_putstr_fd("W Key - Interations increase\n", 1);
	ft_putstr_fd("S Key - Interations decrease\n", 1);
	ft_putstr_fd("D Key - Range color increase\n", 1);
	ft_putstr_fd("A Key - Range color decrease\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
}

void	interation_log(int i, int r)
{
	ft_putstr_fd("MAX interation:  ", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Color Range:  ", 1);
	ft_putnbr_fd(10 - r, 1);
	ft_putstr_fd("\n", 1);
}

void	color_log(int code)
{
	ft_putstr_fd("Color pallete:  ", 1);
	if (code == BERNSTEIN_CODE)
		ft_putstr_fd(BERNSTEIN_MODE, 1);
	if (code == PALLETE_CODE)
		ft_putstr_fd(PALLETE_MODE, 1);
	if (code == RED_CODE)
		ft_putstr_fd(RED_MODE, 1);
	if (code == GREEN_CODE)
		ft_putstr_fd(GREEN_MODE, 1);
	if (code == BLUE_CODE)
		ft_putstr_fd(BLUE_MODE, 1);
	ft_putstr_fd("\n", 1);
}

void	position_log(int x, int y)
{
	ft_putstr_fd("Position: X = ", 1);
	ft_putnbr_fd(x, 1);
	ft_putstr_fd("  Y = ", 1);
	ft_putnbr_fd(y, 1);
	ft_putstr_fd("\n", 1);
}
