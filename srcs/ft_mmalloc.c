/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:55:11 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:55:13 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		*g_alloc[400];
int			g_al = 0;

void		to_free(void)
{
	int i;

	i = -1;
	while (++i < g_al)
		free(g_alloc[i]);
}

void		*ft_malloc(size_t n)
{
	void	*tmp;

	if (!(tmp = malloc(n)))
		return (NULL);
	g_alloc[g_al] = tmp;
	g_al++;
	return (tmp);
}
