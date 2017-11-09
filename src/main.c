/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 14:04:25 by schabaud          #+#    #+#             */
/*   Updated: 2016/10/12 15:38:24 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frc.h"

static	void	show_usage(void)
{
	ft_putstr("   1 : Mandelbrot\n");
	ft_putstr("   2 : Julia\n");
	ft_putstr("   3 : Burning ship\n");
}

static void		option_map(t_all *a, int map)
{
	if (map == 1)
		a->f = &mandelbrot;
	else if (map == 2)
		a->f = &julia;
	else if (map == 3)
		a->f = &burning_ship;
	else
		show_usage();
}

static void		display_fractol(int map)
{
	t_all	a;

	option_map(&a, map);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, WIDTH, HEIGHT, TITLE);
	a.img = mlx_new_image(a.mlx, WIDTH, HEIGHT);
	a.tab = mlx_get_data_addr(a.img, &a.a, &a.b, &a.c);
	draw_fractal(&a);
	display_screen(&a);
}

int				main(int ac, char **av)
{
	int	a;

	if (ac != 2)
	{
		show_usage();
		return (0);
	}
	if (!(a = ft_atoi(av[1])))
		show_usage();
	else
	{
		if (a >= 4)
			show_usage();
		else
			display_fractol(a);
	}
	return (0);
}
