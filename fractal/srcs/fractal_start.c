/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:34:05 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/30 14:35:24 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	re_initiate_data(t_fract *f)
{
	f->dpcol = 0;
	f->mouse_on = 55;
	f->max_iter = 25.;
	f->rot = 0;
	f->exp = 0;
	f->jul_rl = 1.2;
	f->jul_i = -3.2;
	f->pos_x = 5.;
	f->pos_y = 6.;
	f->z = 170.0;
	f->hg_clr = 358.;
	f->dp_clr = 0.800;
	f->vl_clr = 0.92;
	f->key_col = 0;
}

void	fract_start(t_fract *f)
{
	initiate_data(f);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WD, WIN_HG, "F R A C T O L");
	mlx_expose_hook(f->win, fract_create, f);
	mlx_hook(f->win, 6, 64, fract_track_motion, f);
	mlx_hook(f->win, 2, 3, keyboard_hook, f);
	mlx_hook(f->win, 17, 0, esc_button, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_do_key_autorepeaton(f->mlx);
	mlx_loop(f->mlx);
	exit(0);
}

int		fract_track_motion(int x, int y, t_fract *f)
{
	if ((f->flag == 1 || f->flag == 4 || f->flag == 5) && f->mouse_on == 55)
	{
		f->jul_rl = (((3.200 - (-3.20)) / (double)(WIN_WD)) *
			((double)(x))) + (-3.20);
		f->jul_i = (((3.200 - (-3.20)) / (double)(WIN_WD)) *
			((double)(y))) + (-3.20);
		fract_redraw(f, f->key_col);
	}
	return (0);
}

void	fract_rot(t_fract *f, int rad)
{
	if (rad >= 0)
		while (rad >= 360)
			rad -= 360;
	else
		while (rad < 0)
			rad += 360;
	if (rad == 0 && (f->exp = 0) == 0)
		while (f->z < 0)
			f->z *= -1;
	else if (rad == 90 && (f->exp = 1) == 1)
		while (f->z < 0)
			f->z *= -1;
	else if (rad == 180 && (f->exp = 2) == 2)
		while (f->z > 0)
			f->z *= -1;
	else if (rad == 270 && (f->exp = 3) == 3)
		while (f->z > 0)
			f->z *= -1;
	f->min_x = GET_MIN_X;
	f->min_y = GET_MIN_Y;
}
