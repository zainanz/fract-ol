/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:45:16 by zali              #+#    #+#             */
/*   Updated: 2025/05/22 15:07:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_x_y_origin(int x, int y, t_fractol *fractol)
{
	t_complex	dist;

	dist.real = x - (WIDTH / 2.0);
	dist.i = (HEIGHT / 2.0) - y;
	fractol->horizontol_shift += ((dist.real * .25) / 100) * fractol->zoom;
	fractol->verticle_shift += ((dist.i * .25) / 100) * fractol->zoom;
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
	return (1);
}

void	toggle_color(int keycode, t_fractol *fractol)
{
	if (keycode != XK_6)
		fractol->rgb_poly = 0;
	if (keycode == XK_1)
		fractol->color = MAGENTA_BURST;
	else if (keycode == XK_2)
		fractol->color = LIME_SHOCK;
	else if (keycode == XK_3)
		fractol->color = NEON_ORANGE;
	else if (keycode == XK_4)
		fractol->color = HOT_PINK;
	else if (keycode == XK_5)
		fractol->color = AQUA_DREAM;
	else if (keycode == XK_6)
	{
		fractol->rgb_poly = 1;
		fractol->depth = 150;
	}
}

int	handle_keydown(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		close_window(fractol);
	else if (keycode == XK_Left)
		fractol->horizontol_shift -= 0.5 * fractol->zoom;
	else if (keycode == XK_Right)
		fractol->horizontol_shift += 0.5 * fractol->zoom;
	else if (keycode == XK_Up)
		fractol->verticle_shift += 0.5 * fractol->zoom;
	else if (keycode == XK_Down)
		fractol->verticle_shift -= 0.5 * fractol->zoom;
	else if (keycode == XK_Page_Up)
		fractol->zoom *= .80;
	else if (keycode == XK_Page_Down)
		fractol->zoom *= 1.20;
	else if (keycode == XK_KP_Add)
		fractol->depth += 10;
	else if (keycode == XK_KP_Subtract)
		fractol->depth -= 10;
	if ((keycode >= XK_1 && keycode <= XK_6))
		toggle_color(keycode, fractol);
	fractol_render(fractol);
	return (1);
}

int	handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		fractol->zoom *= .80;
	else if (button == 5)
		fractol->zoom *= 1.20;
	move_x_y_origin(x, y, fractol);
	fractol_render(fractol);
	return (1);
}
