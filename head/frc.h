/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 15:57:00 by schabaud          #+#    #+#             */
/*   Updated: 2016/10/17 14:03:46 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRC_H
# define FRC_H
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# define WIDTH 1080
# define HEIGHT 720
# define TITLE "Frac'tool"

typedef struct	s_all
{
	int			a;
	int			b;
	int			c;
	void		*mlx;
	void		*win;
	int			(*f)(struct s_all*, int);
	int			i_max;
	int			lock;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		zoom;
	double		ox;
	double		oy;
	double		xx;
	double		yy;
	double		tmp_zi;
	int			x;
	int			y;
	int			color_back;
	int			color_front;
	void		*img;
	char		*tab;
}				t_all;

void			reset(t_all *a);
int				update(t_all *a);
int				mouse(int k, int x, int y, t_all *a);
int				pos_mouse(int x, int y, t_all *a);
int				event_keyboard(int k, t_all *a);
void			display_screen(t_all *a);
int				mandelbrot(t_all *a, int i);
int				julia(t_all *a, int i);
int				burning_ship(t_all *a, int i);
void			draw_fractal(t_all *a);
void			ft_zoom_in(int x, int y, t_all *a);
void			ft_zoom_out(int x, int y, t_all *a);

#endif
