/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:59:42 by avishnev          #+#    #+#             */
/*   Updated: 2018/03/23 16:30:09 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_fract		*src;

	src = (t_fract*)ft_memalloc(sizeof(t_fract));
	src->argc = ac;
	if (ac != 2)
		return (error_manage(1));
	else if (check_arg(av[1], src) == -1)
		return (0);
	else
		fract_start(src);
	return (0);
}
