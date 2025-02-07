/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:27:03 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 18:25:35 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_check(int ac, char *av[], t_fractol *fractol)
{
	double divisor;

	divisor = 1.0;
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol->name = av[1];
		if (!ft_strcmp(fractol->name, "julia"))
		{
			if (ft_handle(av[2]) || ft_handle(av[3]))
				return (1);
			fractol->julia_x = ft_atof(av[2], divisor);
			fractol->julia_y = ft_atof(av[3], divisor);
		}
		initialize_window(fractol);
		fractol_render(fractol);
		mlx_loop(fractol->mlx_connection);
	}
	else
		return (1);
	return (0);
}

void	f()
{
	system ("leaks a.out");
}

int main(int ac, char **av)
{
	atexit(f);
	t_fractol	fractol;
	if (ft_check(ac, av, &fractol))
		return ((write(2, "Error\n", 6)),1);
	return (0);
}
