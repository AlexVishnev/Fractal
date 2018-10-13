/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculate1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:03:04 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/29 21:04:09 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_norme1(t_fract *f)
{
	if (f->flag == 6)
	{
		f->prev = f->z_rl;
		f->z_rl = fabsl((f->z_rl * f->z_rl) - (f->z_im * f->z_im)) + f->man_rl;
		f->z_im = fabsl(f->prev) * f->z_im * 2.0 + f->man_i;
	}
	else if (f->flag == 7)
	{
		f->prev = f->z_rl;
		f->z_rl = (f->z_rl * f->z_rl) - (f->z_im * f->z_im) + f->man_rl;
		f->z_im = fabsl(f->prev) * f->z_im * 2.0 + f->man_i;
	}
	else if (f->flag > 7)
		ft_norme2(f);
}

void		ft_norme2(t_fract *f)
{
	if (f->flag == 8)
	{
		f->prev = f->z_rl;
		f->z_rl = fabsl((f->z_rl * f->z_rl) - (f->z_im * f->z_im)) + f->man_rl;
		f->z_im = fabsl(f->prev * f->z_im) * -2.0 + f->man_i;
	}
	else if (f->flag == 9)
	{
		f->prev = f->z_rl;
		f->z_rl = fabsl((f->z_rl * f->z_rl) - (f->z_im * f->z_im)) + f->man_rl;
		f->z_im = (f->prev) * fabsl(f->z_im) * -2.0 + f->man_i;
	}
	if (f->flag == 10)
	{
		f->prev = f->z_rl;
		f->z_rl = (f->z_rl * f->z_rl) - (f->z_im * f->z_im) + f->man_rl;
		f->z_im = (fabsl(f->z_rl) + fabsl(f->z_im)) * (fabsl(f->z_rl) +
		fabsl(f->z_im)) - (f->z_rl * f->z_rl) - (f->z_im * f->z_im) + f->man_i;
	}
}
