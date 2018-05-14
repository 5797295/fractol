/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:38:02 by jukim             #+#    #+#             */
/*   Updated: 2018/05/12 22:46:33 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define YEEE t_yee win[32]; pthread_t tid[32];

void	color_it(t_yee *f, int x, int y, int n)
{
	int i;

	i = (x * 4) + (y * f->size);
	f->data[i] = n;
	f->data[++i] = 255 * n * f->color;
	f->data[++i] = n % 255;
}

void	multyeeeeethread(t_yee *f, int i)
{
	YEEE;
	ft_bzero(f->data, WIN * WIN * 4);
	while (++i < 32 && (ft_memcpy((void*)&win[i], f, sizeof(t_yee))))
	{
		win[i].start = i * (WIN / 32);
		win[i].end = (i + 1) * (WIN / 32);
	}
	i = -1;
	while (++i < 32)
	{
		if (f->set == 1)
			pthread_create(&tid[i], NULL, mandelbrot, &win[i]);
		if (f->set == 2)
			pthread_create(&tid[i], NULL, julia, &win[i]);
		if (f->set == 3)
			pthread_create(&tid[i], NULL, genie, &win[i]);
		if (f->set == 4)
			pthread_create(&tid[i], NULL, burning_ship, &win[i]);
		if (f->set == 5)
			pthread_create(&tid[i], NULL, julio, &win[i]);
	}
	while (--i >= 0)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_string_put(f->mlx, f->win, 5, 5, 0x9EFFAA, check(f, "WOOT", 2));
}

char	*check(t_yee *f, char *av, int i)
{
	if (i == 1)
	{
		if (ft_strcmp(av, "Mandelbrot") == 0)
			f->set = 1;
		else if (ft_strcmp(av, "Julia") == 0)
			f->set = 2;
		else if (ft_strcmp(av, "Genie") == 0)
			f->set = 3;
		else if (ft_strcmp(av, "Burning_ship") == 0)
			f->set = 4;
		else if (ft_strcmp(av, "Julio") == 0)
			f->set = 5;
		else
			message(2);
	}
	if (i == 2)
	{
		f->set == 1 ? av = "Mandelbrot Set" : 0;
		f->set == 2 ? av = "Julia Set" : 0;
		f->set == 3 ? av = "Genie Set" : 0;
		f->set == 4 ? av = "Burning Ship Set" : 0;
		f->set == 5 ? av = "Julio Set" : 0;
	}
	return (av);
}

void	message(int i)
{
	if (i == 1)
	{
		ft_putendl("usage: ./fractol <SET>\n");
		ft_putendl("SET LIST:\tMandelbrot\n\t\tJulia\n\t\tGenie");
		ft_putendl("\t\tBurning_ship\n\t\tJulio");
		exit(0);
	}
	else if (i == 2)
	{
		ft_putendl("error: invalid set\n");
		ft_putendl("SET LIST:\tMandelbrot\n\t\tJulia\n\t\tGenie");
		ft_putendl("\t\tBurning_ship\n\t\tJulio");
		exit(0);
	}
	else if (i == 3)
	{
		ft_putendl("\t\tFRACT'OL\n\nKEYS:\n\t[1] - Mandelbrot Set");
		ft_putendl("\t[2] - Julia Set\n\t[3] - Genie Set");
		ft_putendl("\t[4] - Burning Ship Set\n\t[5] - Julio Set");
		ft_putendl("\t[Scroll / -, +] - Zoom In/Out");
		ft_putendl("\t[K, L] - Change Color Spectrum");
		ft_putendl("\t[I, O] - Iteration Up/Down");
		ft_putendl("\t[Arrow Key] - Move Set\n\t[R] - Reset\n\t[ESC] - Exit");
	}
}

int		main(int ac, char **av)
{
	t_yee	*f;

	if (ac != 2)
		message(1);
	f = (t_yee*)malloc(sizeof(t_yee));
	check(f, av[1], 1);
	message(3);
	window(f);
	base_value(f);
	multyeeeeethread(f, -1);
	mlx_hook(f->win, 2, 0, key_hook, f);
	mlx_hook(f->win, 6, 0, cursor_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_loop(f->mlx);
	return (0);
}
