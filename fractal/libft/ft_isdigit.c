/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:32:23 by avishnev          #+#    #+#             */
/*   Updated: 2017/11/06 17:32:24 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdigits(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			return (0);
		if (ft_isdigit(s[i]) && s[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
