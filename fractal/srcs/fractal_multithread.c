/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_multithread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:15:45 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/28 10:18:32 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../include/fractol.h"

int		pixel_put(t_fract *f)
{
	int		i;
	int		x;
	int		y;
	char	*clr;

	x = f->x;
	i = 0;
	y = f->y;
	if (x >= 0)
	{
		i = ((int)f->x * 4) + ((int)f->y * f->size);
		clr = (char*)&f->colour;
		f->img_data[i] = clr[0];
		f->img_data[++i] = clr[1];
		f->img_data[++i] = clr[2];
	}
	return (0);
}

int		fract_create(t_fract *f, int key)
{
	f->img = mlx_new_image(f->mlx, WIN_WD, WIN_HG);
	f->img_data = mlx_get_data_addr(f->img, &f->bits, &f->size, &f->end);
	multi_thread_draw(f, key);
	fractol_help(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	fractol_interface(f);
	return (0);
}

void	fract_draw(t_mlt_thr *t)
{
	t->f->y = WIN_HG / NBR_TH * (t->i);
	fract_rot(t->f, t->f->rot);
	t->f->len = 1030;
	while (t->f->y < WIN_HG / NBR_TH * (t->i + 1))
	{
		t->f->x = 0;
		while (t->f->x < WIN_WD)
		{
			if (t->f->flag == 1)
				calculate_julia(t->f);
			else if (t->f->flag == 2 || t->f->flag == 3)
				calculate_mandelbrot(t->f);
			else if (t->f->flag > 3 && t->f->flag < 6)
				calculate_fractals_j(t->f);
			else if (t->f->flag > 5 && t->f->flag < 11)
				calculate_fractals_m(t->f);
			++t->f->x;
		}
		t->f->y++;
	}
	free(t->f);
	free(t);
}

void	multi_thread_draw(t_fract *f, int key)
{
	pthread_t		thread_draw[NBR_TH];
	int				i;
	t_mlt_thr		*thread;

	i = 0;
	while (i < NBR_TH)
	{
		thread = (t_mlt_thr *)ft_memalloc(sizeof(t_mlt_thr));
		thread->i = i;
		thread->key = key;
		thread->f = (t_fract *)ft_memalloc(sizeof(t_fract));
		ft_memcpy(thread->f, f, sizeof(t_fract));
		pthread_create(&thread_draw[i], NULL,
			(void *)fract_draw, thread);
		++i;
	}
	i = -1;
	while (i++ < NBR_TH)
		pthread_join(thread_draw[i], NULL);
}
