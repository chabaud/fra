/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 15:45:48 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/18 15:47:24 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frc.h"

void		ft_zoom_in(int x, int y, t_all *a)
{
	a->zoom *= 1.1;
	a->xx += x - (WIDTH / 2);
	a->yy += y - (HEIGHT / 2);
}

void		ft_zoom_out(int x, int y, t_all *a)
{
	a->zoom /= 1.1;
	a->xx += x - (WIDTH / 2);
	a->yy += y - (HEIGHT / 2);
}

int			mandelbrot(t_all *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr;
	fa_zi = a->zi * a->zi;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}

int			julia(t_all *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	a->zr = a->x / a->zoom + a->xx / a->zoom;
	a->zi = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr;
	fa_zi = a->zi * a->zi;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}

int			burning_ship(t_all *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	a->zr = 0;
	a->zi = 0;
	fa_zr = a->zr * a->zr;
	fa_zi = a->zi * a->zi;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi + a->cr;
		a->zi = 2 * fabs(a->zi) * fabs(tmp) + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}
