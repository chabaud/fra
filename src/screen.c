/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:32:17 by schabaud          #+#    #+#             */
/*   Updated: 2016/10/07 14:38:43 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frc.h"

void			display_screen(t_all *a)
{
	reset(a);
	update(a);
	mlx_mouse_hook(a->win, mouse, a);
	mlx_hook(a->win, 6, 1L << 6, pos_mouse, a);
	mlx_hook(a->win, 2, 1L << 1, event_keyboard, a);
	mlx_loop(a->mlx);
}

void			reset(t_all *a)
{
	a->lock = 0;
	a->i_max = 25;
	a->zoom = 100;
	a->xx = -(WIDTH / 2);
	a->yy = -(HEIGHT / 2);
	a->zi = 0;
	a->cr = 0.285;
	a->ci = 0.01;
	a->color_back = 0x0;
	a->color_front = 0xFFFF00;
}

int				update(t_all *a)
{
	mlx_clear_window(a->mlx, a->win);
	draw_fractal(a);
	return (0);
}

static void		play_color(t_all *a, int k, int i)
{
	if (i == a->i_max)
	{
		a->tab[k] = a->color_back >> 0;
		a->tab[++k] = a->color_back >> 4;
		a->tab[++k] = a->color_back >> 10;
	}
	else
	{
		a->tab[k] = ((a->color_front / a->i_max) * i);
		a->tab[++k] = ((a->color_front / a->i_max) * i) >> 14;
		a->tab[++k] = ((a->color_front / a->i_max) * i) >> 8;
	}
}

void			draw_fractal(t_all *a)
{
	int			i;

	a->x = -1;
	a->tmp_zi = a->zi;
	while (++a->x < WIDTH)
	{
		a->y = -1;
		while (++a->y < HEIGHT)
		{
			i = -1;
			a->zr = 0;
			i = a->f(a, i);
			a->zi = a->tmp_zi;
			if (a->i_max > 0)
				play_color(a, (a->x * 4 + a->y * WIDTH * 4), i);
			else
				a->i_max = 1;
		}
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}
