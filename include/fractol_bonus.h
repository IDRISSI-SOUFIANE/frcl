#ifndef FRACTOL_H
#define FRACTOL_H

#include "../minilibx_opengl/mlx.h"
#include <libc.h>

#define WIDTH 800
#define HEIGHT 800

#define BLACK 0x000000
#define WHITE 0xFFFFFF

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
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractol;

typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;


/*utils.c*/
int	ft_strncmp(char *s1, char *s2, int n);
int	ft_handle(char *s);
int	check_sign(char *s, int *i);
double	ft_atof(char *s, double divisor);

/*fractol.c*/
void	initialize_window(t_fractol *fractol);

/*render.c*/
void	fractol_render(t_fractol *fractol);
void	draw_pixel(int x, int y, t_fractol *fractol);
void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractal);
void	my_pixel_put(int x, int y, t_img *img, int color);

/*math.c*/
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);


/*event.c*/
void	handle_event(t_fractol *fractal);

/*initialize*/
void	declare_info(t_fractol *fractol);
void	initialize(t_complex *z, t_complex *c, t_fractol *fractal);

#endif