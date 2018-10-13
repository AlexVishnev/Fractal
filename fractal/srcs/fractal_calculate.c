/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:10:04 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/23 19:10:06 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_julia(t_fract *f)
{
	f->z_rl = GET_J_RL;
	f->z_im = GET_J_IM;
	f->i = -1.0;
	f->md = 2;
	while (++f->i < f->max_iter && (f->z_rl * f->z_rl + f->z_im * f->z_im) < 4)
	{
		f->prev = f->z_rl;
		f->z_rl = (f->z_rl * f->z_rl) - (f->z_im * f->z_im) + f->jul_rl;
		f->z_im = f->md * f->z_im * f->prev + f->jul_i;
	}
	f->colour = colour_get(f);
	pixel_put(f);
}

void	calculate_mandelbrot(t_fract *f)
{
	f->i = -2.0;
	f->z_rl = 0.0;
	f->z_im = 0.0;
	f->md = (f->flag == 2) ? 2 : -2;
	f->man_rl = GET_M_RL;
	f->man_i = GET_M_IM;
	while (++f->i < f->max_iter && (f->z_rl * f->z_rl + f->z_im * f->z_im) < 4)
	{
		f->prev = f->z_rl;
		f->z_rl = (f->z_rl * f->z_rl) - (f->z_im * f->z_im) + f->man_rl;
		f->z_im = f->md * f->z_im * f->prev + f->man_i;
	}
	f->colour = colour_get(f);
	pixel_put(f);
}

void	calculate_fractals_m(t_fract *f)
{
	f->i = -2.0;
	f->z_rl = 0.0;
	f->z_im = 0.0;
	f->md = 2;
	f->man_rl = GET_M_RL;
	f->man_i = GET_M_IM;
	while (++f->i < f->max_iter && (f->z_rl * f->z_rl + f->z_im * f->z_im) < 4)
		ft_norme1(f);
	f->colour = colour_get(f);
	pixel_put(f);
}

void	calculate_fractals_j(t_fract *f)
{
	f->z_rl = GET_J_RL;
	f->z_im = GET_J_IM;
	f->i = -1.0;
	f->md = 2;
	while (++f->i < f->max_iter && (f->z_rl * f->z_rl + f->z_im * f->z_im) < 4)
		ft_norme(f);
	f->colour = colour_get(f);
	pixel_put(f);
}

void	ft_norme(t_fract *f)
{
	if (f->flag == 4)
	{
		f->prev = f->z_rl;
		f->z_rl = fabsl(f->z_rl * f->z_rl - f->z_im * f->z_im) + f->jul_rl;
		f->z_im = f->md * f->z_im * f->prev + f->jul_i;
	}
	else if (f->flag == 5)
	{
		f->prev = (f->z_rl * f->z_rl * f->z_rl) - (f->z_im * f->z_im *
			f->z_rl) - (2 * f->z_rl * f->z_im * f->z_im) + f->jul_rl;
		f->z_rl = f->prev;
		f->z_im = (6 * f->z_rl * f->z_rl * f->z_im) - (f->z_im *
			f->z_im * f->z_im) + f->jul_i;
	}
}
