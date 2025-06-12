/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:24:14 by zali              #+#    #+#             */
/*   Updated: 2025/05/22 15:08:10 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define ERROR_MSG \
	"CMD:\n1. ./fractol <mandelbrot>\n2. ./fractol <julia> <real> <imaginary>."
# define WIDTH 800
# define HEIGHT 800

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST   0xFF00FF  // A vibrant m agenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct mlx_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	char	*title;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	verticle_shift;
	double	horizontol_shift;
	double	zoom;
	int		depth;
	int		julia;
	double	real;
	double	i;
	int		color;
	int		rgb_poly;
}	t_fractol;

// String Helper
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *str, int fd);
int			valid_num(char *str);
double		ft_extract_double(char *str);

// init
void		display_init(t_fractol *fractol);
void		fractol_init(t_fractol *fractol, char *argv[]);
void		event_init(t_fractol *fractol);
void		set_fractol(t_fractol *fractol);

//Events
int			close_window(t_fractol *fractol);
int			handle_keydown(int keycode, t_fractol *fractol);
int			handle_mouse(int button, int x, int y, t_fractol *fractol);

// render
void		fractol_render(t_fractol *fractol);
int			rgb_color(t_fractol *fractol, int interations);

// Math utils
double		ft_scale_value(double unscaled_num, double new_min, double new_max);

#endif
