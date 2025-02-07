/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:30 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/07 12:27:24 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if ((s1[i] != s2[i]))
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);	
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
