/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:52:48 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 22:52:11 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_window(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (NULL == fractol->mlx_connection)
		return ((write(2, "Error\n", 6), exit(1)));
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH,
			HEIGHT, fractol->name);
	if (NULL == fractol->mlx_window)
		(mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window),
			free(fractol->mlx_connection), write(2, "Error\n", 6), exit(1));
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractol->img.img_ptr)
		(mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window),
			free(fractol->mlx_connection), write(2, "Error\n", 6), exit(1));
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len,
			&fractol->img.endian);
	if (NULL == fractol->img.pixels_ptr)
		(mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr),
			mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window),
			free(fractol->mlx_connection), write(2, "Error\n", 6), exit(1));
	handle_event(fractol);
	declare_info(fractol);
}
