/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:55:55 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:55:57 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		g_counter;

int		ft_readtexture(char *str, char *s2, int *g_counter)
{
	int j;

	j = 0;
	*g_counter += 1;
	if ((j = open(ft_split((const char *)str, ' ')[1], O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		write(1, "texture error\n", 14);
		return (1);
	}
	else
		ft_strcpy(s2, ft_split((const char *)str, ' ')[1]);
	return (0);
}

int		ft_isconv(void)
{
	if (!ft_strncmp(g_cub.line, "R ", 2) || !ft_strncmp(g_cub.line, "NO ", 3))
		return (0);
	else if (!ft_strncmp(g_cub.line, "EA ", 3))
		return (0);
	else if (!ft_strncmp(g_cub.line, "WE ", 3))
		return (0);
	else if (!ft_strncmp(g_cub.line, "SO ", 3))
		return (0);
	else if (!ft_strncmp(g_cub.line, "F ", 2))
		return (0);
	else if (!ft_strncmp(g_cub.line, "C ", 2))
		return (0);
	else if (!ft_strncmp(g_cub.line, "S ", 2))
		return (0);
	else if (g_cub.line[0] == '\0' || g_cub.line[0] == '1'
			|| g_cub.line[0] == ' ')
		return (0);
	else
	{
		write(1, "Error\nFile error\n", 17);
		exit(-1);
	}
	return (0);
}

int		ft_readhelp(void)
{
	if (!ft_strncmp(g_cub.line, "R ", 2))
		if (ft_read(g_cub.line, &g_counter))
			return (1);
	if (!ft_strncmp(g_cub.line, "NO ", 3))
		if (ft_readtexture(g_cub.line, g_text.textno, &g_counter))
			return (1);
	if (!ft_strncmp(g_cub.line, "EA ", 3))
		if (ft_readtexture(g_cub.line, g_text.textea, &g_counter))
			return (1);
	if (!ft_strncmp(g_cub.line, "WE ", 3))
		if (ft_readtexture(g_cub.line, g_text.textwe, &g_counter))
			return (1);
	if (!ft_strncmp(g_cub.line, "SO ", 3))
		if (ft_readtexture(g_cub.line, g_text.textso, &g_counter))
			return (1);
	if (!ft_strncmp(g_cub.line, "F ", 2))
		if (ft_readcolor(g_cub.line, &g_counter, &g_file.floor, "F "))
			return (1);
	if (!ft_strncmp(g_cub.line, "C ", 2))
		if (ft_readcolor(g_cub.line, &g_counter, &g_file.ceilling, "C "))
			return (1);
	if (!ft_strncmp(g_cub.line, "S ", 2))
		if (ft_readtexture(g_cub.line, g_text.textsp, &g_counter))
			return (1);
	return (ft_isconv());
}

int		ft_helpread(int fd)
{
	while (get_next_line(fd, &g_cub.line))
	{
		if (ft_readhelp())
			return (1);
		if ((g_counter == 8 || g_counter == -1) && (g_cub.line[0] == ' '
					|| g_cub.line[0] == '1'))
		{
			g_counter = -1;
			ft_strcpy(g_data.map[g_data.y_size], g_cub.line);
			g_data.y_size++;
			g_count++;
		}
		else if (g_counter == -1 && g_cub.line[0] == '\0')
			ft_strcpy(g_data.map[g_data.y_size++], "error");
		free(g_cub.line);
	}
	if ((g_cub.line[0] == ' ' || g_cub.line[0] == '1'))
	{
		ft_strcpy(g_data.map[g_data.y_size], g_cub.line);
		g_data.y_size++;
		g_count++;
		g_counter = -1;
	}
	return (0);
}

int		ft_readfile(char *str)
{
	int fd;
	int i;

	i = 0;
	g_count = 0;
	g_counter = 0;
	g_data.y_size = 0;
	fd = open(str, O_RDONLY);
	if (ft_helpread(fd))
		return (1);
	free(g_cub.line);
	ft_max();
	if (g_counter != -1)
	{
		write(1, "Error\n", 6);
		write(1, "somthing missing\n", 16);
		return (1);
	}
	return (0);
}
