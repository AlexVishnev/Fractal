/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:10:41 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/23 19:10:44 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		colour_shade(int col, double var, t_fract *f)
{
	int		red;
	int		green;
	int		blue;

	if (var > 0.0)
		var = 0.0;
	red = floor((double)((col >> 16) & 0xFF) -
		(double)((double)((col >> 16) & 0xFF) * var));
	green = floor((double)((col >> 8) & 0xFF) -
		(double)((double)((col >> 8) & 0xFF) * var));
	blue = floor((double)(col & 0xFF) -
		(double)((double)(col & 0xFF) * var));
	if (f->key_col == 11)
		return (COL);
	return (COL);
}

t_rgb	hsv_rgb(t_hsv hsv)
{
	t_rgb		rgb;
	double		p;
	double		q;
	double		t;

	(hsv.h == 360.) ? (hsv.h = 0.) : (hsv.h /= 60.);
	p = hsv.v * (1. - hsv.s);
	q = hsv.v * (1. - (hsv.s * (hsv.h - floor(hsv.h))));
	t = hsv.v * (1. - (hsv.s * (1. - (hsv.h - floor(hsv.h)))));
	rgb = (t_rgb){.red = 0., .green = 0., .blue = 0.};
	if (hsv.s == 0.)
		rgb = (t_rgb){.red = hsv.v, .green = hsv.v, .blue = hsv.v};
	if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.red = hsv.v, .green = t, .blue = p};
	if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.red = q, .green = hsv.v, .blue = p};
	if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.red = p, .green = hsv.v, .blue = t};
	if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.red = p, .green = q, .blue = hsv.v};
	if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.red = t, .green = p, .blue = hsv.v};
	if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.red = hsv.v, .green = p, .blue = q};
	return (rgb);
}

int		colour_get(t_fract *f)
{
	t_rgb		rgb;
	t_hsv		h;

	if (f->i == f->max_iter)
		return (0x000000);
	else if (f->i >= 0 && f->i <= 7)
		return (cut_shit_colour(f->key_col));
	else
	{
		h.h = f->hg_clr + ((360. / f->max_iter + f->dpcol) * f->i);
		h.s = f->dp_clr;
		h.v = f->vl_clr - (((f->vl_clr - 0.10) / 100.0) * f->i + f->dpcol);
		while (h.h < 0.)
			h.h += 360;
		while (h.h > 360.)
			h.h -= 360;
		rgb = hsv_rgb(h);
	}
	return (colour_hexd(rgb, f));
}

int		hsv_to_hex(double h, double s, double v, t_fract *f)
{
	t_hsv		hsv;
	t_rgb		rgb;

	hsv = (t_hsv){.h = h, .s = s, .v = v};
	rgb = hsv_rgb(hsv);
	return (colour_hexd(rgb, f));
}

int		colour_hexd(t_rgb h, t_fract *f)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(h.red * 255.0) + f->dpcol;
	green = (int)(h.green * 255.0) + f->dpcol;
	blue = (int)(h.blue * 255.0) + f->dpcol;
	if (f->key_col == 15)
		return (COL_R);
	else if (f->key_col == 5)
		return (COL_G);
	else if (f->key_col == 11)
		return (COL_B);
	else if (f->key_col == 0)
		return (COL);
	return (f->key_col == 13 ? B_W : COL);
}
