CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_FILE = ft_printf.c\
ft_aff_utils.c\
ft_aff_utils1.c\
ft_printf.c\
ft_do_s.c\
ft_do_d.c\
ft_do_x.c\
ft_do_u.c\
ft_do_c.c\
ft_do_p.c\
ft_is.c\
ft_do_pourcent.c\
ft_fill.c\

INC=ft_printf.h
SRC = ${SRC_FILE}
OBJS = ${SRC:.c=.o}

all: ${NAME}

$(NAME): ${OBJS} ${INC}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

.c.o:  ${SRC} 
	gcc ${CFLAGS} -c -I. $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS} ${BONUS}

fclean: clean
	rm ${NAME}

make bonus : ${BONUS} ${OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS}
	ranlib ${NAME}

re: clean all