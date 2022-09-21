NAME = libasm.a

NFLAGS = nasm -f elf64
CFLAGS = gcc -Wall -Wextra -Werror main.c

SRC =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s  \
		ft_read.s   \
		ft_strdup.s \

OBJ = $(SRC:%.s=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.s
	$(NFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
