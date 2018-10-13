/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_gui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:21:27 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/30 14:21:29 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol_interface1(t_fract *f)
{
	char	*name;

	name = "a";
	if (f->flag == 1)
		name = ft_strdup("Julia");
	else if (f->flag == 2)
		name = ft_strdup("Mandelbrot");
	else if (f->flag == 3)
		name = ft_strdup("Tricorn");
	else if (f->flag == 4)
		name = ft_strdup("Julia Quadr");
	else if (f->flag == 5)
		name = ft_strdup("Star");
	else if (f->flag == 6)
		name = ft_strdup("Celtic Heart");
	else if (f->flag == 7)
		name = ft_strdup("Heart Mandelbrot");
	else if (f->flag == 8)
		name = ft_strdup("Buffalo");
	else if (f->flag == 9)
		name = ft_strdup("Perpendic. Buffalo");
	else if (f->flag == 10)
		name = ft_strdup("Burning ship");
	mlx_string_put(f->mlx, f->win, WIN_WD - 231, 229, RED, name);
	free(name);
}

void	fractol_interface(t_fract *f)
{
	char	*a;

	a = ft_itoa(f->max_iter);
	mlx_string_put(f->mlx, f->win, WIN_WD - 167, 209, RED, a);
	free(a);
	mlx_string_put(f->mlx, f->win, 41, 35, YELLOW, "<<Controls Keys>>");
	mlx_string_put(f->mlx, f->win, 37, 63, GREEN, "ARROWS = move");
	mlx_string_put(f->mlx, f->win, 37, 83, GREEN, "I/O = +/- iteration");
	mlx_string_put(f->mlx, f->win, 37, 103, GREEN, "-/+ = Zoom");
	mlx_string_put(f->mlx, f->win, 37, 123, GREEN, "Y/T = rotate");
	mlx_string_put(f->mlx, f->win, 37, 143, GREEN, "M = Mouse (on/of)");
	mlx_string_put(f->mlx, f->win, 37, 200, GREEN, "Q = psychedelic");
	mlx_string_put(f->mlx, f->win, 37, 163, GREEN, "R/G/B/W/A/Q = colour");
	mlx_string_put(f->mlx, f->win, 37, 183, GREEN, "space = default");
	mlx_string_put(f->mlx, f->win, 37, 258, YELLOW, "<<Controls Mouse>>");
	mlx_string_put(f->mlx, f->win, 37, 286, f->interf_clr, "wheel && RMB/LMB");
	mlx_string_put(f->mlx, f->win, 37, 306, f->interf_clr, "Zoom out/in");
	fractol_interface1(f);
	fractol_interface2(f);
}

void	fractol_interface2(t_fract *f)
{
	mlx_string_put(f->mlx, f->win, WIN_WD - 249, 35, YELLOW, "<<Fractals>>");
	mlx_string_put(f->mlx, f->win, WIN_WD - 299, 65, GREEN, "1 = Julia");
	mlx_string_put(f->mlx, f->win, WIN_WD - 299, 86, GREEN, "2 = Mandelbrot");
	mlx_string_put(f->mlx, f->win, WIN_WD - 299, 110,
		GREEN, "< / > = switch fractal");
	mlx_string_put(f->mlx, f->win, WIN_WD - 299, 209,
		GREEN, "iteration = [    ]");
	mlx_string_put(f->mlx, f->win, WIN_WD - 249, 178,
		YELLOW, "<<Parametrs>>");
	mlx_string_put(f->mlx, f->win, WIN_WD - 299, 229, GREEN, "NAME = ");
}

void	fractol_help(t_fract *f)
{
	int		j;
	int		clr;

	clr = (f->key_col == 13) ? 0x00 : 0xffffff;
	j = 0;
	f->x = 15;
	f->y = 15;
	while (j++ < 4)
		draw_line(253 + j, 233 + j, clr, f);
	f->y = 247;
	while (j++ < 8)
		draw_line(253 + j - 4, 346 + j - 4, clr, f);
	f->x = WIN_WD - 311;
	f->y = 15;
	while (j++ < 12)
		draw_line(WIN_WD - 25 + j - 8, 150 + j - 8, clr, f);
	f->y = 170;
	f->x = WIN_WD - 311;
	while (j++ < 16)
		draw_line((WIN_WD - 25) + j - 12, 270 + j - 12, clr, f);
}

void	draw_line(int x, int y, int colour, t_fract *f)
{
	int		c1;
	int		c2;

	c1 = f->x;
	c2 = f->y;
	f->colour = colour;
	while (f->x <= x && pixel_put(f) == 0)
		f->x++;
	while (f->y <= y && pixel_put(f) == 0)
		f->y++;
	while (f->x > c1 && pixel_put(f) == 0)
		f->x--;
	while (f->y > c2 && pixel_put(f) == 0)
		f->y--;
}
