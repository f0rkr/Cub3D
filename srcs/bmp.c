/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:00:30 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:53:14 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

unsigned char	g_bmpfileheader[14] = {'B', 'M', 0,
	0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
unsigned char	g_bmpinfoheader[40] = {40, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
unsigned char	g_bmppad[3] = {0, 0, 0};

t_color			hex_to_rgb(unsigned int hexcolor)
{
	t_color col;

	col.r = ((hexcolor >> 16) & 255);
	col.g = ((hexcolor >> 8) & 255);
	col.b = (hexcolor & 255);
	return (col);
}

void			ft_set_header(void)
{
	int filesize;

	filesize = 54 + 3 * g_file.width * g_file.height;
	g_bmpfileheader[2] = (unsigned char)(filesize);
	g_bmpfileheader[3] = (unsigned char)(filesize >> 8);
	g_bmpfileheader[4] = (unsigned char)(filesize >> 16);
	g_bmpfileheader[5] = (unsigned char)(filesize >> 24);
	g_bmpinfoheader[4] = (unsigned char)(g_file.width);
	g_bmpinfoheader[5] = (unsigned char)(g_file.width >> 8);
	g_bmpinfoheader[6] = (unsigned char)(g_file.width >> 16);
	g_bmpinfoheader[7] = (unsigned char)(g_file.width >> 24);
	g_bmpinfoheader[8] = (unsigned char)(g_file.height);
	g_bmpinfoheader[9] = (unsigned char)(g_file.height >> 8);
	g_bmpinfoheader[10] = (unsigned char)(g_file.height >> 16);
	g_bmpinfoheader[11] = (unsigned char)(g_file.height >> 24);
}

int				write_bmp_header(int fd)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_set_header();
	write(fd, g_bmpfileheader, 14);
	write(fd, g_bmpinfoheader, 40);
	while (i < g_file.height)
	{
		j = 0;
		while (j < g_file.width)
		{
			write(fd, g_mlx.img.data + (g_file.width *
			(g_file.height - i) + j), 3);
			j++;
		}
		write(fd, g_bmppad, (4 - (g_file.width * 3) % 4) % 4);
		i++;
	}
	return (1);
}

void			bmp(void)
{
	int fd;

	fd = open("save.bmp", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write_bmp_header(fd);
	close(fd);
}
