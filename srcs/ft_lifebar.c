/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lifebar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:51:41 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:54:49 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_lifebar(void)
{
	int		x;
	int		y;
	void	*img_ptr;
	int		tab[5];

	x = 10;
	y = 10;
	img_ptr = mlx_xpm_file_to_image(g_mlx.mlx, "./texture/do.xpm",
			&tab[0], &tab[1]);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.wind, img_ptr, 0, 0);
}
