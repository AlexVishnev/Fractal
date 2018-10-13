/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:17:15 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/30 13:18:39 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		cut_shit_colour(int col)
{
	if (col == 15)
		return (0x3d0000);
	if (col == 5)
		return (0x002608);
	if (col == 11)
		return (0x000c38);
	if (col == 0)
		return (0x420000);
	else
		return (col == 13 ? 0xffffff : 0x420000);
}

int		check_arg(char *av, t_fract *f)
{
	if (!ft_isdigits(av))
	{
		ft_putendl(HELP);
		return (-1);
	}
	f->flag = ft_atoi(av);
	if (f->flag > 2 || f->flag < 1)
	{
		ft_putendl(HELP);
		return (-1);
	}
	return (0);
}

int		error_manage(int flag)
{
	if (flag == 1)
		ft_putendl(ERR1);
	ft_putendl(HELP);
	return (-1);
}

void	initiate_data(t_fract *f)
{
	f->dpcol = 0;
	f->mouse_on = 0;
	f->max_iter = 25.;
	f->rot = 0;
	f->exp = 0;
	f->jul_rl = 1.2;
	f->jul_i = 3.2;
	f->pos_x = 5.;
	f->pos_y = 6.;
	f->z = 170.0;
	f->hg_clr = 358.;
	f->dp_clr = 0.800;
	f->vl_clr = 0.92;
	f->interf_clr = RED;
	f->key_col = 0;
}

void	fract_redraw(t_fract *f, int key)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	fract_create(f, key);
}
