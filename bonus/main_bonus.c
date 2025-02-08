/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:27:03 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/08 18:39:08 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	ft_check(int ac, char *av[], t_fractol *fractol)
{
	double	divisor;

	divisor = 1.0;
	if ((ac == 2 && !ft_strcmp(av[1], "Burning_Ship")))
	{
		fractol->name = av[1];
		initialize_window(fractol);
		fractol_render(fractol);
		mlx_loop(fractol->mlx_connection);
	}
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ft_check(ac, av, &fractol))
		(ft_putstr(ERROR), exit(1));
	return (0);
}
