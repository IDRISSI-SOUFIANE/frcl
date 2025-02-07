/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:03 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 21:56:41 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdlib.h> 

# define ERROR "Error: please respect the compilation command:\n\
\t./fractol <write (mandelbrot) or (julia)>\n\
\t\tif chose julia write the coordinate (x and y)\n"
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0X1C1C1C

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int		nb_of_iteration;
	int		escape_value;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;


typedef struct s_map
{
    double n_mn;
    double n_mx;
    double o_mn;
    double o_mx;
} t_map;


int		ft_strcmp(char *s1, char *s2);
int		ft_handle(char *s);
int		check_sign(char *s, int *i);
double	ft_atof(char *s, double divisor);
void	ft_putstr(char *s);

void	initialize_window(t_fractol *fractol);

void	fractol_render(t_fractol *fractol);
void	draw_pixel(int x, int y, t_fractol *fractol);
void	my_pixel_put(int x, int y, t_img *img, int color);

double map(double n, t_map range);
// double		map(double n, double n_mn, double n_mx, double o_mn, double o_mx);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void	handle_event(t_fractol *fractal);

void	declare_info(t_fractol *fractol);
void	initialize(t_complex *z, t_complex *c, t_fractol *fractal);
#endif
