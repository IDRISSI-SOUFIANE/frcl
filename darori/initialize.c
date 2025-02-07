/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:21:37 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 18:16:12 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	declare_info(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->nb_of_iteration = 42;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->zoom = 1;
}

void	initialize(t_complex *z, t_complex *c, t_fractol *fractal)
{	
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}