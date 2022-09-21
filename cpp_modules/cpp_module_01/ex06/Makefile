NAME = karenFilter
CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = Karen.cpp main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@ $(CC) $(CFLAGS) $(SRCS) -o $(NAME) -fsanitize=address

run:
	./$(NAME)
clean:
	@ rm -f $(NAME)

fclean : clean

re : fclean all
