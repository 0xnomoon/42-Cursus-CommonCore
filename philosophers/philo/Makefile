# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 14:09:53 by nomoon            #+#    #+#              #
#    Updated: 2021/10/22 16:43:38 by nomoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = clang
HEAD = -Iinclude
CFLAGS = -Wall -Wextra $(DEBUG)
#  DEBUG = -fsanitize=address -g3

FILES = main.c parse.c free.c \
				init.c time.c time_to_eat.c \
				checking.c message.c \
				
SRC_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.c=%.o))

all :   $(NAME) 

$(NAME) : $(OBJ_PATH) $(OBJ)
	$(CC) -pthread $(CFLAGS) $(HEAD) $(OBJ) -o ${NAME}

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

print:
	@echo $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all