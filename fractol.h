/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:42:14 by jukim             #+#    #+#             */
/*   Updated: 2018/05/12 22:52:16 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <complex.h>
# define WIN 640

typedef struct	s_yee
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
	int		start;
	int		end;
	float	zoom;
	int		iter;
	float	x_move;
	float	y_move;
	int		set;
	int		cursor_x;
	int		cursor_y;
	int		color;
}				t_yee;

/*
** main.c
*/

int				main(int ac, char **av);
void			multyeeeeethread(t_yee *f, int i);
void			color_it(t_yee *f, int x, int y, int n);
void			message(int i);
char			*check(t_yee *f, char *av, int i);

/*
** fractol_sets.c
*/

void			*mandelbrot(void *win);
void			*julia(void *win);
void			*genie(void *win);
void			*burning_ship(void *win);
void			*julio(void *win);

/*
** setting.c
*/

void			window(t_yee *f);
void			base_value(t_yee *f);
int				key_hook(int key, t_yee *f);
int				cursor_hook(int i, int j, t_yee *f);
int				mouse_hook(int key, int x, int y, t_yee *f);

#endif
