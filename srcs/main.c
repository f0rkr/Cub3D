/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:58:21 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:58:23 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_exit(int key, void *ptr)
{
	key = (int)ptr;
	mlx_destroy_window(g_mlx.mlx, g_mlx.wind);
	exit(0);
}

int		ft_dynamic(void)
{
	mlx_hook(g_mlx.wind, 17, 0L, ft_exit, (void *)0);
	mlx_hook(g_mlx.wind, 2, 0, ft_press, (void *)0);
	mlx_hook(g_mlx.wind, 3, 0, ft_unpress, (void *)0);
	ft_update();
	ft_lifebar();
	return (0);
}

void	ft_init(void)
{
	g_cot = 0;
	g_sprtnum = 0;
	g_save = 0;
	g_mlx.x = 0;
	g_3d.top = 3;
}

int		ft_printerro(void)
{
	write(1, "Error\n", 6);
	write(1, "Arg Error\n", 10);
	return (0);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 3)
		return (ft_printerro());
	if ((!(argv[1] == NULL) && ft_strncmp(argv[1], "map.cub", 7)) ||
			(!(argv[2] == NULL) && ft_strncmp(argv[2], "--save", 5)))
		return (ft_printerro());
	if (!(argv[2] == NULL) && strcmp(argv[2], "--save") == 0)
		g_save = 1;
	if (ft_readfile(argv[1]))
		return (0);
	ft_map();
	ft_direction();
	ft_settexture();
	if (!ft_map_error())
		return (0);
	mlx_loop_hook(g_mlx.mlx, ft_dynamic, (void *)0);
	mlx_loop(g_mlx.mlx);
	return (0);
}
