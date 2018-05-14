/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 00:57:00 by jukim             #+#    #+#             */
/*   Updated: 2018/05/12 22:46:42 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WOOP t_yee *f = (t_yee *)win; int i, j; double z[6];
#define DC double complex c1=-0.778-0.116*I; double complex c2=0.274-0.008*I;

void	*julio(void *win)
{
	WOOP;
	while (f->start < f->end && (i = -1))
	{
		while (++i < WIN && (j = -1))
		{
			z[0] = 1.5 * (i - WIN / 2) / (WIN / 4 * f->zoom) + f->x_move;
			z[1] = (f->start - WIN / 2) / (WIN / 6 * f->zoom) + f->y_move;
			z[2] = 0;
			z[3] = 0;
			while (++j < f->iter)
			{
				z[2] = z[0];
				z[3] = z[1];
				z[0] = fabs((z[2] * z[2] - z[3] * z[3]) -
						0.662 + 0.2 * f->cursor_x / 250);
				z[1] = fabs(2 * z[2] * z[3] + 0.282 - 0.2 * f->cursor_y / 250);
				if (z[0] * z[0] + z[1] * z[1] >= 4)
					break ;
			}
			if (j < f->iter)
				color_it(f, i, f->start, 1000 * j);
		}
		f->start++;
	}
	return (NULL);
}

void	*burning_ship(void *win)
{
	WOOP;
	while (f->start < f->end && (i = -1))
	{
		while (++i < WIN && (j = -1))
		{
			z[0] = 1.5 * (i - WIN / 2) / (WIN / 4 * f->zoom) + f->x_move;
			z[1] = (f->start - WIN / 2) / (WIN / 6 * f->zoom) + f->y_move;
			z[2] = 0;
			z[3] = 0;
			while (++j < f->iter)
			{
				z[4] = z[2];
				z[5] = z[3];
				z[2] = fabs((z[4] * z[4] - z[5] * z[5]) + z[0]);
				z[3] = fabs((2 * z[4] * z[5]) + z[1]);
				if (z[2] * z[2] + z[3] * z[3] >= 4)
					break ;
			}
			if (j < f->iter)
				color_it(f, i, f->start, 1000 * j);
		}
		f->start++;
	}
	return (NULL);
}

void	*genie(void *win)
{
	WOOP;
	while (f->start < f->end && (i = -1))
	{
		while (++i < WIN && (j = -1))
		{
			z[0] = 1.5 * (i - WIN / 2) / (WIN / 4 * f->zoom) + f->x_move;
			z[1] = (f->start - WIN / 2) / (WIN / 6 * f->zoom) + f->y_move;
			z[2] = 0;
			z[3] = 0;
			while (z[2] * z[2] + z[3] * z[3] <= 4 && ++j < f->iter)
			{
				z[4] = z[2];
				z[5] = z[3];
				z[2] = (z[4] * z[4] - z[5] * z[5]) + z[0];
				z[3] = fabs((2 * z[4] * z[5]) + z[1]);
			}
			if (j < f->iter)
				color_it(f, i, f->start, 1000 * j);
		}
		f->start++;
	}
	return (NULL);
}

void	*julia(void *win)
{
	DC;
	WOOP;
	while (f->start < f->end && (i = -1))
	{
		while (++i < WIN && (j = -1))
		{
			z[0] = 1.5 * (i - WIN / 2) / (WIN / 4 * f->zoom) + f->x_move;
			z[1] = (f->start - WIN / 2) / (WIN / 6 * f->zoom) + f->y_move;
			z[2] = 0;
			z[3] = 0;
			while (++j < f->iter)
			{
				z[2] = z[0];
				z[3] = z[1];
				z[0] = (z[2] * z[2] - z[3] * z[3]) + c1 * f->cursor_x / 250;
				z[1] = (2 * z[2] * z[3]) + c2 * f->cursor_y / 250;
				if (z[0] * z[0] + z[1] * z[1] >= 4)
					break ;
			}
			if (j < f->iter)
				color_it(f, i, f->start, 1000 * j);
		}
		f->start++;
	}
	return (NULL);
}

void	*mandelbrot(void *win)
{
	WOOP;
	while (f->start < f->end && (i = -1))
	{
		while (++i < WIN && (j = -1))
		{
			z[0] = 1.5 * (i - WIN / 2) / (WIN / 4 * f->zoom) + f->x_move;
			z[1] = (f->start - WIN / 2) / (WIN / 6 * f->zoom) + f->y_move;
			z[2] = 0;
			z[3] = 0;
			while (z[2] * z[2] + z[3] * z[3] <= 4 && ++j < f->iter)
			{
				z[4] = z[2];
				z[5] = z[3];
				z[2] = (z[4] * z[4] - z[5] * z[5]) + z[0];
				z[3] = (2 * z[4] * z[5]) + z[1];
			}
			if (j < f->iter)
				color_it(f, i, f->start, 1000 * j);
		}
		f->start++;
	}
	return (NULL);
}
