# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 14:50:02 by oel-ouar          #+#    #+#              #
#    Updated: 2020/03/11 00:35:03 by oel-ouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cub3D
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/ft_common.c srcs/bmp.c srcs/direction.c srcs/ft_atoi.c srcs/ft_lifebar.c srcs/ft_iswall.c srcs/ft_map.c srcs/ft_max.c srcs/ft_norm.c srcs/ft_mmalloc.c srcs/ft_drawrays.c srcs/ft_error.c srcs/ft_readcolor.c srcs/ft_readr.c srcs/ft_settexture.c srcs/ft_readmap.c srcs/ft_render3d.c srcs/ft_press.c srcs/ft_strcpy.c srcs/ft_strisdigit.c srcs/ft_strncmp.c srcs/ft_split.c srcs/ft_tohex.c srcs/ft_sprite.c srcs/ft_update_sprite.c srcs/ft_strtrim.c srcs/main.c
LIB = libs/getnextline.a
FRAMEWORK = -framework
MININC = /usr/local/include
INCLUDES = includes/
MINILIB = libmlx.a 
MINILIBX = minilibx/
MINISRC = /usr/local/lib
all: $(NAME)
$(NAME):
	@make --directory=$(MINILIBX)
	$(CC) $(FLAGS) $(SRCS) $(LIB) -I $(MININC) -o3 -I $(MINILIBX) -I $(INCLUDES) -L $(MINISRC)  $(MINILIBX)$(MINILIB) $(FRAMEWORK) OpenGL $(FRAMEWORK) AppKit -o $(NAME) -Ofast
clean:
	@make clean --directory=$(MINILIBX)
	@rm -rf cub3D

fclean: clean
	@echo "Deleting Programe"

bonus:

re: fclean all
	@echo "Rebuilding"
