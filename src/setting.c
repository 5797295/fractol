/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 09:20:12 by jukim             #+#    #+#             */
/*   Updated: 2018/05/12 22:46:38 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define KEY key==20?f->set=3:0; key==21?f->set=4:0; key==23?f->set=5:0;

void	window(t_yee *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN, WIN, "FRAC'TROLOLOL");
	f->img = mlx_new_image(f->mlx, WIN, WIN);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->size, &f->endian);
}

void	base_value(t_yee *f)
{
	f->start = 0;
	f->end = WIN;
	f->zoom = 1;
	f->iter = 50;
	f->x_move = 0;
	f->y_move = 0;
	f->color = 1;
}

int		key_hook(int key, t_yee *f)
{
	if (key == 53)
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	key == 40 && f->color < 10 ? f->color += 1 : 0;
	key == 37 && f->color > 1 ? f->color -= 1 : 0;
	key == 18 ? f->set = 1 : 0;
	key == 19 ? f->set = 2 : 0;
	KEY;
	key == 24 ? f->zoom *= 1.1 : 0;
	key == 27 && f->zoom / 1.1 > 0 ? f->zoom /= 1.1 : 0;
	key == 34 ? f->iter += 1 : 0;
	key == 31 && f->iter > 1 ? f->iter -= 1 : 0;
	key == 123 ? f->x_move -= 0.3 / f->zoom : 0;
	key == 124 ? f->x_move += 0.3 / f->zoom : 0;
	key == 125 ? f->y_move += 0.3 / f->zoom : 0;
	key == 126 ? f->y_move -= 0.3 / f->zoom : 0;
	key == 15 ? base_value(f) : 0;
	if (key == 37 || key == 40 || key == 20 || key == 18 || key == 19 ||
			key == 15 || key == 31 || key == 24 || key == 27 || key == 34
			|| (key >= 123 && key <= 126) || key == 21 || key == 23)
		multyeeeeethread(f, -1);
	return (0);
}

int		cursor_hook(int i, int j, t_yee *f)
{
	if ((f->set == 2 || f->set == 5) && i >= 0 && j >= 0)
	{
		f->cursor_x = (i - WIN / 2);
		f->cursor_y = (j - WIN / 2);
		multyeeeeethread(f, -1);
	}
	return (0);
}

int		mouse_hook(int key, int x, int y, t_yee *f)
{
	float i;
	float j;

	i = (float)((2 * x - WIN) / (WIN / 2) / f->zoom);
	j = (float)((2 * y - WIN) / (WIN / 2) / f->zoom);
	if (key == 4)
	{
		f->x_move += (float)(i / 4);
		f->y_move += (float)(j / 4);
		f->zoom *= 1.1;
	}
	if (key == 5 && f->zoom / 1.1 > 0)
	{
		f->x_move -= (float)(i / 4);
		f->y_move -= (float)(j / 4);
		f->zoom /= 1.1;
	}
	if (key == 4 || key == 5)
		multyeeeeethread(f, -1);
	return (0);
}
