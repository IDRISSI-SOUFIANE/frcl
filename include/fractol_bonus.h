/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:56:15 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/08 22:28:10 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdlib.h> 
# include <math.h>

# define ERROR "Error: please respect the compilation command:\n\
\t./fractol <write (Burning_Ship)>\n"
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define BLUE 0X1C1C1C

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
	double	offset_x;
	double	offset_y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

}	t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_map
{
	double	n_mn;
	double	n_mx;
	double	o_mn;
	double	o_mx;
}	t_map;

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *s);

void		initialize_window(t_fractol *fractol);

void		fractol_render(t_fractol *fractol);
void		draw_pixel(int x, int y, t_fractol *fractol, double *xtemp);
void		my_pixel_put(int x, int y, t_img *img, int color);

double		map(double n, t_map range);

void		handle_event(t_fractol *fractal);

void		declare_info(t_fractol *fractol);
void		initialize(int *x, int *y, t_complex *c, t_fractol *fractol);
void		initialize2(t_complex *z, t_fractol *fractol);
#endif
