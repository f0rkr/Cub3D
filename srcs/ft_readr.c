/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:56:10 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:56:15 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_prieor(void)
{
	write(1, "Error\n", 6);
	write(1, "resolution error\n", 17);
	return (1);
}

void	ft_cont(char *str)
{
	if ((ft_atoi(ft_split((const char *)str, ' ')[1]) > 2550 &&
				ft_atoi(ft_split((const char *)str, ' ')[2]) > 1440) ||
			(ft_atoi(ft_split((const char *)str, ' ')[1]) < 0 &&
			ft_atoi(ft_split((const char *)str, ' ')[2]) < 0))
	{
		g_file.width = 2550;
		g_file.height = 1440;
	}
	else if (ft_atoi(ft_split((const char *)str, ' ')[1]) > 2550 ||
			ft_atoi(ft_split((const char *)str, ' ')[1]) < 0)
	{
		g_file.width = 2550;
		g_file.height = ft_atoi(ft_split((const char *)str, ' ')[2]);
	}
	else if (ft_atoi(ft_split((const char *)str, ' ')[2]) > 1440 ||
			ft_atoi(ft_split((const char *)str, ' ')[2]) < 0)
	{
		g_file.width = ft_atoi(ft_split((const char *)str, ' ')[1]);
		g_file.height = 1440;
	}
	else
	{
		g_file.width = ft_atoi(ft_split((const char *)str, ' ')[1]);
		g_file.height = ft_atoi(ft_split((const char *)str, ' ')[2]);
	}
}

int		ft_read(char *str, int *count)
{
	*count += 1;
	if (!(ft_split((const char *)str, ' ')[1]) || !(ft_split((const char *)str,
					' ')[2]) || ft_split((const char *)str, ' ')[3])
		return (ft_prieor());
	else
	{
		if (ft_strisdigit(ft_split((const char *)str, ' ')[1]) ||
				ft_strisdigit(ft_split((const char *)str, ' ')[2]))
			return (ft_prieor());
		else
			ft_cont(str);
	}
	return (0);
}
