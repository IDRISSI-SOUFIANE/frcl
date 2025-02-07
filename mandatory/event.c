/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:58:27 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 18:41:01 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(0);
}

int	key_press(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		close_window(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractol->zoom *= 1.05;
	else if (button == 4)
		fractol->zoom *= 0.95;
	fractol_render(fractol);
	return (0);
}

void	handle_event(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, key_press, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_window, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_hook, fractol);
}
