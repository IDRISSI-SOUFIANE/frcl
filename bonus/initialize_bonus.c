/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:21:37 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/09 10:54:29 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	declare_info(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->nb_of_iteration = 300;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->zoom = 1;
}

void	initialize(int *x, int *y, t_complex *c, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "Burning_Ship"))
	{
		c->x = map((*x), (t_map){-2.0, 2.0, 0, WIDTH})
			* fractol->zoom + fractol->offset_x;
		c->y = map((*y), (t_map){-2.0, 2.0, 0, HEIGHT})
			* fractol->zoom + fractol->offset_y;
	}
}

void	initialize2(t_complex *z, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "Burning_Ship"))
	{
		z->x = 0.0;
		z->y = 0.0;
	}
}
