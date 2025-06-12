/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:30:23 by zali              #+#    #+#             */
/*   Updated: 2025/05/21 18:32:07 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc failed");
	exit(EXIT_FAILURE);
}

void	set_fractol(t_fractol *fractol)
{
	fractol->horizontol_shift = 0;
	fractol->verticle_shift = 0;
	fractol->zoom = 1;
	fractol->depth = 50;
	fractol->color = LIME_SHOCK;
	fractol->rgb_poly = 0;
}

void	fractol_init(t_fractol *fractol, char *argv[])
{
	set_fractol(fractol);
	if (!valid_num(argv[2]) || !valid_num(argv[3]))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(argv[1], "julia"))
	{
		fractol->real = ft_extract_double(argv[2]);
		fractol->i = ft_extract_double(argv[3]);
		fractol->julia = 1;
	}
	else
		fractol->julia = 0;
}

void	display_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH,
			HEIGHT,
			fractol->title);
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_display(fractol->mlx_connection);
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_len, &fractol->img.endian);
}

void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyRelease, KeyReleaseMask,
		handle_keydown, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
		close_window, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask,
		handle_mouse, fractol);
}
