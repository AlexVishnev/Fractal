/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:56 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/23 19:25:43 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define ERR1 "Error: Wrong usage\n"
# define ERR2 "Error: Invalid input"
# define HELP "USAGE: 1 - Juila\n       2 - Mandelbrot"

# define NBR_TH 16
# define WIN_WD 1280
# define WIN_HG 1050

# define STEP_Z (f->z * 0.15)
# define GET_POS_X ((double)(WIN_HG / 2 + f->pos_y) - (double)(y))
# define GET_POS_Y ((double)(WIN_WD / 2 + f->pos_x) - (double)(x))
# define GET_MIN_X (((WIN_WD / 2 + f->pos_x) / (f->z / 2)) / -2)
# define GET_MIN_Y (((WIN_HG / 2 + f->pos_y) / (f->z / 2)) / -2)
# define IN_WIND x >= 0 && x < WIN_WD && y >= 0 && y < WIN_HG
# define M1 f->min_x : ((double)(f->y) / f->z) + f->min_y
# define M2 f->min_y : ((double)(f->x) / f->z) + f->min_x
# define J1 f->min_x : ((double)(f->y) / f->z) + f->min_y
# define J2 f->min_y : ((double)(f->x) / f->z) + f->min_x
# define GET_J_RL (f->exp == 0 || f->exp == 2) ? ((double)(f->x) / f->z) + J1
# define GET_J_IM (f->exp == 0 || f->exp == 2) ? ((double)(f->y) / f->z) + J2
# define GET_M_RL (f->exp == 0 || f->exp == 2) ? ((double)(f->x) / f->z) + M1
# define GET_M_IM (f->exp == 0 || f->exp == 2) ? ((double)(f->y) / f->z) + M2

# define KEY_A (key == 0)
# define ARR_R (key == 124)
# define ARR_D (key == 125)
# define ARR_L (key == 123)
# define ARR_U (key == 126)
# define KEY_S (key == 1)
# define KEY_M (key == 46)
# define KEY_Q (key == 12)
# define KEY_W (key == 13)
# define KEY_G (key == 5)
# define KEY_R (key == 15)
# define KEY_B (key == 11)
# define KEY_Y (key == 16)
# define KEY_T (key == 17)
# define KEY_SPACE (key == 49)
# define KEY_O (key == 31)
# define KEY_I (key == 34)
# define KEY_NUM_P (key == 69)
# define KEY_NUM_M (key == 78)
# define KEY_NUM_1 (key == 83)
# define KEY_NUM_2 (key == 84)
# define KEY_NUM_3 (key == 85)
# define KEY_NUM_M (key == 78)

# define RED 0xb70d0d
# define GREEN 0x0eb744
# define YELLOW 0xffff00
# define BLUE 0x0036f9

# define COL_B ((red & 0x06) << 16) + ((green & 0x00) << 8) + (blue & 0xff)
# define COL_G ((red & 0x00) << 16) + ((green & 0xff) << 8) + (blue & 0x0c)
# define COL_R ((red & 0x9E) << 16) + ((green & 0x00) << 8) + (blue & 0x00)
# define COL ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff)
# define B_W ((red | 0xff) << 16) + ((green | 0xff) << 8) + (blue | 0xff)

typedef struct	s_fract
{
	int			dpcol;
	int			mouse_on;
	int			argc;
	int			exp;
	int			rot;
	int			flag;
	int			bits;
	int			size;
	int			end;
	int			x;
	int			y;
	int			len;
	int			colour;
	int			interf_clr;
	int			key_col;
	float		min_x;
	float		min_y;
	double		z;
	double		max_iter;
	double		pos_x;
	double		pos_y;
	double		i;
	double		hg_clr;
	double		dp_clr;
	double		vl_clr;
	char		*img_data;
	long double	jul_rl;
	long double	jul_i;
	long double	man_i;
	long double	man_rl;
	long double	z_rl;
	long double	z_im;
	long double	prev;
	long double	md;
	void		*win;
	void		*mlx;
	void		*img;
}				t_fract;

typedef	struct	s_colour
{
	double		s_red;
	double		s_green;
	double		s_blue;
	double		hg;
	double		dp;
	double		vl;
	double		p_red;
	double		p_blue;
	double		p_green;
}				t_colour;

typedef	struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef	struct	s_rgb
{
	double		red;
	double		green;
	double		blue;
}				t_rgb;

typedef struct	s_mlt_thr
{
	int			i;
	int			key;
	t_fract		*f;
}				t_mlt_thr;

int				cut_shit_colour(int col);
int				fract_track_motion(int x, int y, t_fract *f);
void			fract_rot(t_fract *f, int rad);
void			fract_draw(t_mlt_thr *f);
void			multi_thread_draw(t_fract *f, int key);

void			fract_help(void);
void			fract_start(t_fract *f);
int				fract_create(t_fract *f, int key);
void			initiate_data(t_fract *f);
void			re_initiate_data(t_fract *f);

int				check_arg(char *av, t_fract *f);
int				error_manage(int flag);
int				pixel_put(t_fract *f);
int				entry_point(t_fract *f);

int				colour_get(t_fract *f);
int				colour_hexd(t_rgb c, t_fract *f);
int				colour_shade(int col, double shade, t_fract *f);
t_rgb			hsv_rgb(t_hsv hsv);

int				esc_button(int key, t_fract *f);
void			fractol_help(t_fract *f);
void			draw_line(int x, int y, int colour, t_fract *f);
void			fractol_interface(t_fract *f);
int				keyboard_hook(int key, t_fract *f);
void			fract_redraw(t_fract *f, int key);
int				mouse_hook(int button, int x, int y, t_fract *f);
void			keyboard_contr_p1(t_fract *f, int key);
void			keyboard_contr_p2(t_fract *f, int key);

int				hsv_to_hex(double h, double s, double v, t_fract *f);

void			calculate_julia(t_fract *f);
void			calculate_mandelbrot(t_fract *f);
void			calculate_fractals_m(t_fract *f);
void			calculate_fractals_j(t_fract *f);
void			ft_norme(t_fract *f);
void			ft_norme1(t_fract *f);
void			ft_norme2(t_fract *f);
void			ft_norme3(t_fract *f);
void			fractol_interface1(t_fract *f);
void			keyboard_contr_p3(t_fract *f, int key);
void			fractol_interface2(t_fract *f);

#endif
