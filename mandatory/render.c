/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:09:43 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 22:08:22 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

// void	draw_pixel(int x, int y, t_fractol *fractol)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	int			i;
// 	int			color;

// 	color = 0;
// 	i = 0;
// 	z.x = (map(x, -2, +2, 0, WIDTH) * fractol->zoom);
// 	z.y = (map(y, +2, -2, 0, HEIGHT) * fractol->zoom);

// 	// handle_julia
// 	initialize(&z, &c, fractol);
	
// 	while (i < fractol->nb_of_iteration)
// 	{
// 		z = sum_complex(square_complex(z), c);
// 		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
// 		{
// 			color = map(i, BLACK, WHITE, 0, fractol->nb_of_iteration);
// 			my_pixel_put(x, y, &fractol->img, color);
// 			return ;
// 		}
// 		++i;
// 	}
// 	my_pixel_put(x, y, &fractol->img, BLACK);
// }

// void draw_pixel(int x, int y, t_fractol *fractol)
// {
//     t_complex   z;
//     t_complex   c;
//     int         i;
//     int         color;

//     color = 0;
//     i = 0;

//     t_map x_range = {-2, 2, 0, WIDTH};
//     t_map y_range = {2, -2, 0, HEIGHT};
//     z.x = map(x, x_range) * fractol->zoom;
//     z.y = map(y, y_range) * fractol->zoom;
//     initialize(&z, &c, fractol);
//     while (i < fractol->nb_of_iteration)
//     {
//         z = sum_complex(square_complex(z), c);
//         if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
//         {
//             t_map color_range = {BLACK, WHITE, 0, fractol->nb_of_iteration};
//             color = map(i, color_range);
//             my_pixel_put(x, y, &fractol->img, color);
//             return ;
//         }
//         ++i;
//     }
//     my_pixel_put(x, y, &fractol->img, BLACK);
// }

// void draw_pixel(int x, int y, t_fractol *fractol)
// {
// 	t_complex   c;
//     int         i = 0;
//     int         color = 0;
// 	t_complex   z;

//     t_complex   z = {
//         .x = map(x, (t_map){-2, 2, 0, WIDTH}) * fractol->zoom,
//         .y = map(y, (t_map){2, -2, 0, HEIGHT}) * fractol->zoom
//     };
//     t_complex   c;
//     int         i = 0;
//     int         color = 0;

//     initialize(&z, &c, fractol);

//     while (i < fractol->nb_of_iteration)
//     {
//         z = sum_complex(square_complex(z), c);
//         if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
//         {
//             color = map(i, (t_map){BLACK, WHITE, 0, fractol->nb_of_iteration});
//             my_pixel_put(x, y, &fractol->img, color);
//             return ;
//         }
//         ++i;
//     }
//     my_pixel_put(x, y, &fractol->img, BLACK);
// }


void draw_pixel(int x, int y, t_fractol *fractol)
{
    t_complex   z;
    t_complex   c;
    int         i = 0;
    int         color = 0;

    z.x = map(x, (t_map){-2, 2, 0, WIDTH}) * fractol->zoom;
    z.y = map(y, (t_map){2, -2, 0, HEIGHT}) * fractol->zoom;

    initialize(&z, &c, fractol);

    while (i < fractol->nb_of_iteration)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
        {
            color = map(i, (t_map){BLACK, WHITE, 0, fractol->nb_of_iteration});
            my_pixel_put(x, y, &fractol->img, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &fractol->img, BLACK);
}




void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
