/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:09:43 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/08 18:58:05 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	draw_pixel(int x, int y, t_fractol *fractol, double *xtemp)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	color = 0;
	initialize(&x, &y, &c, fractol);
	initialize2(&z, fractol);
	while (i < fractol->nb_of_iteration)
	{
		*xtemp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = fabs(2.0 * z.x * z.y) + c.y;
		z.x = fabs(*xtemp);
		if ((z.x * z.x) + (z.y * z.y) >= 4.0)
			break ;
		i++;
	}
	if (i == fractol->nb_of_iteration)
		color = 0;
	else
		color = (i * 255 / fractol->nb_of_iteration) << 9;
	my_pixel_put(x, y, &fractol->img, color);
}

void	fractol_render(t_fractol *fractol)
{
	int			x;
	int			y;
	double		xtemp;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractol, &xtemp);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
