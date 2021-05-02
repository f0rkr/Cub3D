/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:57:48 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:57:52 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_trimappend(char const *s1, char *str, int start, int end)
{
	int i;

	i = 0;
	while (start < (end + 1))
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	while (s1[start] != '\0')
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	while (s1[end] != s1[start])
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	if (!(str = ft_malloc(sizeof(char) * ((end - start) + 2))))
		return (0);
	return (ft_trimappend(s1, str, start, end));
}
