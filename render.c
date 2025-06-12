/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:00:48 by zali              #+#    #+#             */
/*   Updated: 2025/05/25 10:02:20 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	set_c(t_fractol *fractol, t_complex *c, t_complex *z)
{
	if (fractol->julia)
	{
		c->real = fractol->real;
		c->i = fractol->i;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void	rgb_handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		t_real;

	i = -1;
	z.real = ft_scale_value(x, -2, 2)
		* fractol->zoom + fractol->horizontol_shift;
	z.i = ft_scale_value(y, 2, -2)
		* fractol->zoom + fractol->verticle_shift;
	set_c(fractol, &c, &z);
	while (++i < fractol->depth)
	{
		t_real = (z.real * z.real) - (z.i * z.i);
		z.i = (2 * z.real * z.i) + c.i;
		z.real = t_real + c.real;
		if ((((z.real * z.real) + (z.i * z.i)) > 4))
			break ;
	}
	my_pixel_put(x, y, &fractol->img, rgb_color(fractol, i));
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		t_real;

	i = -1;
	z.real = ft_scale_value(x, -2, 2)
		* fractol->zoom + fractol->horizontol_shift;
	z.i = ft_scale_value(y, 2, -2)
		* fractol->zoom + fractol->verticle_shift;
	set_c(fractol, &c, &z);
	while (++i < fractol->depth)
	{
		t_real = (z.real * z.real) - (z.i * z.i);
		z.i = (2 * z.real * z.i) + c.i;
		z.real = t_real + c.real;
		if ((((z.real * z.real) + (z.i * z.i)) > 4))
		{
			if (i < 10)
				break ;
			return (my_pixel_put(x, y, &fractol->img,
					ft_scale_value(i, fractol->color, BLACK)));
		}
	}
	my_pixel_put(x, y, &fractol->img, BLACK);
}

void	fractol_render(t_fractol *fractol)
{
	int		x;
	int		y;
	void	(*func)(int, int, t_fractol *);

	if (fractol->rgb_poly)
		func = rgb_handle_pixel;
	else
		func = handle_pixel;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			func(x++, y, fractol);
		y++;
	}
	mlx_put_image_to_window(
		fractol->mlx_connection,
		fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
