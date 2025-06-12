/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:44 by zali              #+#    #+#             */
/*   Updated: 2025/05/21 18:31:49 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strcmp("mandelbrot", argv[1]))
		|| (argc == 4 && !ft_strcmp("julia", argv[1])))
	{
		fractol.title = argv[1];
		fractol_init(&fractol, argv);
		display_init(&fractol);
		fractol_render(&fractol);
		event_init(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
}
