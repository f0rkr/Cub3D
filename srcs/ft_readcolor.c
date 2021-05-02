/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:55:39 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:55:44 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_prierror(void)
{
	write(1, "Error\n", 6);
	write(1, "color error\n", 12);
	return (1);
}

int		ft_checktrim(char *s1, char *s2, char *s3)
{
	int i;

	i = 0;
	s1 = ft_strtrim(s1, " \t");
	s2 = ft_strtrim(s2, " \t");
	s3 = ft_strtrim(s3, " \t");
	while (s1[i])
		if (s1[i] == ' ' || s1[i++] == '\t')
			return (1);
	i = 0;
	while (s2[i])
		if (s2[i] == ' ' || s2[i++] == '\t')
			return (1);
	i = 0;
	while (s3[i])
		if (s3[i] == ' ' || s3[i++] == '\t')
			return (1);
	return (0);
}

void	ft_colorhelp(t_color *color, char *str)
{
	color->r = ft_atoi(ft_split((const char *)str, ',')[0]);
	color->g = ft_atoi(ft_split((const char *)str, ',')[1]);
	color->b = ft_atoi(ft_split((const char *)str, ',')[2]);
}

int		ft_readcolor(char *str, int *count, t_color *color, char *s)
{
	*count += 1;
	str = ft_strtrim((const char *)str, s);
	if (!ft_split((const char *)str, ',')[0] || !ft_split((const char *)str,
				',')[1] || !ft_split((const char *)str, ',')[2]
			|| ft_common(str) != 2)
		return (ft_prierror());
	else if (ft_strisdigit(ft_split((const char *)str, ',')[0]) ||
			ft_strisdigit(ft_split((const char *)str, ',')[1])
			|| ft_strisdigit(ft_split((const char *)str, ',')[2]))
		return (ft_prierror());
	else
	{
		if (ft_atoi(ft_split((const char *)str, ',')[0]) > 255 ||
				ft_atoi(ft_split((const char *)str, ',')[1]) > 255 ||
				ft_atoi(ft_split((const char *)str, ',')[2]) > 255)
			return (ft_prierror());
		else if (ft_checktrim(ft_split((const char *)str, ',')[0],
			ft_split((const char *)str, ',')[2],
			ft_split((const char *)str, ',')[1]))
			return (ft_prierror());
		else
			ft_colorhelp(color, str);
	}
	return (0);
}
