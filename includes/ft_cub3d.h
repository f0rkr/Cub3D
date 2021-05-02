/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 05:34:41 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 07:00:47 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include "get_next_line.h"

# define TAIL_SIZE	64
# define NOSE_SIZE	64
# define PI			3.14159265359
# define CONV		(PI/180)
# define INV       (180/PI)
# define FOV		60 * CONV

# define NUM_TEXTURE 5
# define EAST	1
# define WEST	2
# define NORTH  3
# define SOUTH  4
# define SPT    5
# define SPEED  2

typedef struct		s_color
{
	double r;
	double g;
	double b;
}					t_color;

typedef	struct		s_file
{
	int			width;
	int			height;
	t_color		floor;
	t_color		ceilling;
}					t_file;

typedef struct		s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}					t_img;

typedef struct		s_mlx
{
	void	*mlx;
	void	*wind;
	float	x;
	float	y;
	t_img	img;
}					t_mlx;

typedef struct		s_key
{
	int		straight;
	int		back;
	int		right;
	int		left;
	int		rightd;
	int		leftd;
	int		up;
	int		down;
	int		exit;
}					t_key;

typedef struct		s_ply
{
	float		x;
	float		y;
	float		distance;
}					t_ply;

typedef struct		s_data
{
	int		x_size;
	int		y_size;
	int		max;
	char	map[1024][1024];
}					t_data;

typedef struct		s_rays
{
	float	wallhx;
	float	wallhy;
	int		down;
	int		up;
	int		right;
	int		left;
	int		hitvert;
	float	distance;
	float	angle;
}					t_rays;

typedef struct		s_3d
{
	float	top;
}					t_3d;

typedef struct		s_draws
{
	int		tocheck;
	float	rayang;
	float	xsps;
	float	ysps;
	float	xint;
	float	yint;
	float	nhorx;
	float	nhory;
	float	hwhitx;
	float	hwhity;
	int		fhwhit;
	int		vwallhit;
	float	hdistnc;
	float	vdistnc;
	float	vwhitx;
	float	vwhity;
}					t_draws;

typedef struct		s_wall
{
	int		txtx;
	int		txty;
	int		*texture[5];
}					t_wall;

typedef struct		s_cub
{
	char	*line;
}					t_cub;

typedef struct		s_text
{
	char	textno[50];
	char	textso[50];
	char	textwe[50];
	char	textea[50];
	char	textsp[50];
}					t_text;

typedef struct		s_sprt
{
	float	x;
	float	y;
	float	distance;
	int		sprtnum;
}					t_sprt;

t_sprt				g_sprt[1024];
t_mlx				g_mlx;
t_ply				g_ply;
t_data				g_data;
t_rays				g_rays[2550];
t_key				g_key;
t_3d				g_3d;
t_wall				g_wall;
t_cub				g_cub;
t_file				g_file;
t_text				g_text;
t_draws				g_draws;

float				g_direction;
int					g_cot;
char				g_playp;
int					g_save;
int					g_sprtnum;
int					g_count;

void				ft_map();
void				ft_readmap();
void				ft_drawrays();
int					ft_update();
void				ft_render3d();
int					ft_press(int key, void *param);
int					ft_unpress(int key, void *param);
void				ft_walltextur();
int					ft_iswall(float x, float y);
int					ft_iswal(float x, float y);
void				ft_texture();
int					ft_map_error();
int					ft_player_error(int i, int j);
void				ft_direction();
void				ft_lifebar();
int					ft_readfile(char *str);
char				**ft_split(char const *str, char c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strcpy(char *dest, char *src);
unsigned int		ft_tohex(int r, int g, int b);
int					ft_strisdigit(char *str);
char				*ft_strtrim(char const *s1, char const *set);
void				bmp();
int					ft_isprt(float y, float x);
void				ft_sprite();
void				ft_update_sprite();
void				*ft_malloc(size_t n);
void				to_free(void);
void				ft_settexture(void);
int					ft_common(char *str);
int					ft_readcolor(char *str, int *count,
		t_color *color, char *s);
int					ft_read(char *str, int *count);
void				ft_max(void);
float				ft_norm(float rayang);
#endif
