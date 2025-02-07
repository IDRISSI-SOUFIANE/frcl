#include "../include/fractol.h"

double map(double n, t_map range)
{
    return ((range.n_mx - range.n_mn) * ((n - range.o_mn) / (range.o_mx - range.o_mn)) + range.n_mn);
}


t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}