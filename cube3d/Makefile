# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:51:09 by elbouju           #+#    #+#              #
#    Updated: 2020/03/09 19:33:31 by elbouju          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
NAME = cub3D

SRC_FILE = cub3d.c \
ft_parse.c \
draw.c \
ft_calcul.c \
ft_error.c \
ft_errormessage.c \
ft_keypress.c \
ft_parse1.c \
ft_split.c \
ft_utils.c \
ft_window.c \
get_next_line_utils.c \
get_next_line.c \
init.c \
rgb_to_hex.c \
screenshot.c \
sprite_utils.c \
sprite.c \
texture.c \
ft_move.c \
utils.c \
utils1.c

SRC_PATH = src/
INC= cube3d.h
SRC = ${addprefix ${SRC_PATH}, $(SRC_FILE)}
OBJS = ${SRC:%.c=%.o}
FRAMEWORK = -framework OpenGL -framework AppKit

all: ${NAME}


$(NAME): ${OBJS} ${INC}
	@gcc ${CFLAGS} -I include -g3 -l mlx ${FRAMEWORK} ${OBJS} -o ${NAME}

%.o : %.c
	@echo Compiling $<
	@gcc -c -I include/ $< -o $@

clean:
	@rm -f ${OBJS} ${BONUS}

fclean: clean
	@rm ${NAME}

bonus :

re: clean all
