/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:30 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 18:15:37 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);	
	return (s1[i] - s2[i]);
}

int	ft_handle(char *s)
{
	int	i;
	int	dot_count;

	dot_count = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '.')
			return (1);
		if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (1);
		}
		i++;
	}
	return (0);
}
int	check_sign(char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}
double	ft_atof(char *s, double divisor)
{
	int		i;
	int		sign;
	double	res;
	double	fraction;

	res = 0.0;
	fraction = 0.0;
	i = 0;
	 while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	sign = check_sign(s, &i);
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		{
			fraction = fraction * 10.0 + (s[i++] - '0');
			divisor *= 10.0;
		}
		res += fraction / divisor;
	}
	return (res * sign);
}
