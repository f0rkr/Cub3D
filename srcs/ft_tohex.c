/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:57:59 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:58:02 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_tohex(int r, int g, int b)
{
	unsigned int color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}
