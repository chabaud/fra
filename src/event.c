/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:27:35 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/27 15:23:12 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frc.h"

int				pos_mouse(int x, int y, t_all *a)
{
	static int	tx;
	static int	ty;

	if (a->lock == 0)
	{
		a->cr = (float)(x + 595 - WIDTH) / 200;
		a->ci = (float)(y + 360 - HEIGHT) / 300;
		return (update(a));
	}
	return (0);
}

int				mouse(int k, int x, int y, t_all *a)
{
	if (k == 1)
		ft_zoom_in(x, y, a);
	else if (k == 2)
		ft_zoom_out(x, y, a);
	else if (k == 5)
		ft_zoom_in(x, y, a);
	else if (k == 4)
		ft_zoom_out(x, y, a);
	else
		return (0);
	return (update(a));
}

static int		event_keyboard_sub(int k, t_all *a)
{
	if (k == 13)
		a->ci += 0.001;
	else if (k == 1)
		a->ci -= 0.001;
	else if (k == 0)
		a->cr -= 0.001;
	else if (k == 2)
		a->cr += 0.001;
	else if (k == 6)
		--a->color_front;
	else if (k == 7)
		++a->color_front;
	else if (k == 8)
		a->color_front += 256;
	else if (k == 11)
		a->color_front -= 65536;
	else if (k == 45)
		a->color_front += 65536;
	else if (k == 37)
		a->lock = (a->lock) ? 0 : 1;
	return (update(a));
}

static int		event_keyboard_ex(int k, t_all *a)
{
	if (k == 12)
		a->zi -= 0.01;
	else if (k == 83)
		a->f = &mandelbrot;
	else if (k == 84)
		a->f = &julia;
	else if (k == 85)
		a->f = &burning_ship;
	return (event_keyboard_sub(k, a));
}

int				event_keyboard(int k, t_all *a)
{
	if (k == 53)
		exit(0);
	else if (k == 34)
		a->i_max++;
	else if (k == 32)
		a->i_max--;
	else if (k == 31)
		reset(a);
	else if (k == 69)
		ft_zoom_in(0, 0, a);
	else if (k == 78)
		ft_zoom_out(0, 0, a);
	else if (k == 123)
		a->xx -= 100;
	else if (k == 124)
		a->xx -= -100;
	else if (k == 126)
		a->yy -= 100;
	else if (k == 125)
		a->yy -= -100;
	else if (k == 14)
		a->zi += 0.01;
	else
		return (event_keyboard_ex(k, a));
	return (update(a));
}
