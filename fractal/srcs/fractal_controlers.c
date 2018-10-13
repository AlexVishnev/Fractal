/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_controlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:10:24 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/23 19:10:26 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		keyboard_hook(int key, t_fract *f)
{
	if (key == 53)
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		system("leaks --quiet fractol");
		exit(0);
	}
	else
	{
		keyboard_contr_p1(f, key);
		keyboard_contr_p2(f, key);
		fract_redraw(f, key);
	}
	return (0);
}

int		mouse_hook(int butt, int x, int y, t_fract *f)
{
	if (f->mouse_on == 54 && (IN_WIND))
	{
		if (butt == 1)
		{
			f->pos_y = round(GET_POS_Y);
			f->pos_x = round(GET_POS_X);
		}
		else if (butt == 2)
		{
			f->pos_y = round(GET_POS_Y * 0.65);
			f->pos_x = round(GET_POS_X * 0.65);
		}
		if (butt == 1 || butt == 5)
			f->z += STEP_Z;
		if ((butt == 2 || butt == 4) && (f->z > 10 || f->z < -10))
			f->z -= STEP_Z;
		fract_redraw(f, 0);
	}
	return (0);
}

void	keyboard_contr_p1(t_fract *f, int key)
{
	if (KEY_M)
	{
		f->interf_clr = (f->interf_clr == GREEN) ? RED : GREEN;
		f->mouse_on = (f->mouse_on == 55) ? 54 : 55;
	}
	if (KEY_O && f->max_iter > 2)
		f->max_iter -= 2.;
	if (KEY_I && f->max_iter < 1400)
		f->max_iter += 2.;
	if (KEY_Y)
		f->rot += 180;
	if (KEY_T)
		f->rot += 90;
	if (KEY_NUM_P)
		f->z += STEP_Z;
	if (KEY_NUM_M && (f->z > 10 || f->z < -10))
		f->z -= STEP_Z;
	if (KEY_NUM_1 && f->flag != 1)
		f->flag = 1;
	if (KEY_NUM_2 && f->flag != 2)
		f->flag = 2;
}

void	keyboard_contr_p2(t_fract *f, int key)
{
	if (ARR_L)
		f->pos_x -= 50.;
	if (ARR_R)
		f->pos_x += 50.;
	if (ARR_D)
		f->pos_y += 50.;
	if (ARR_U)
		f->pos_y -= 50.;
	if (KEY_B)
		f->key_col = 11;
	if (KEY_R)
		f->key_col = 15;
	if (KEY_W)
		f->key_col = 13;
	if (KEY_G)
		f->key_col = 5;
	keyboard_contr_p3(f, key);
}

void	keyboard_contr_p3(t_fract *f, int key)
{
	if (KEY_SPACE)
		initiate_data(f);
	if (key == 47 && f->flag < 10)
	{
		re_initiate_data(f);
		f->flag++;
	}
	if (key == 43 && f->flag > 1)
	{
		f->flag--;
		re_initiate_data(f);
	}
	if (KEY_Q)
	{
		f->dpcol++;
		if (f->dpcol >= 255)
			f->dpcol *= -1;
	}
	if (KEY_A)
		f->key_col = 0;
}
