/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:45:00 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/17 01:45:05 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (arg_verify(argc, argv, &win))
	{
		set_params(argv, &win);
		set_window(&win);
	}
	else
	{
		args_help();
	}
	return (0);
}
