NAME = megaphone

FLAGS = -Werror -Wall -Wextra

SRCS = megaphone.cpp

OBJS = $(SRCS:%.cpp=%.o)

INC = 

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	clang++ $(FLAGS) $(OBJS) -I . -o $(NAME)

%.o : %.cpp
	clang++ -c $< -I .

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all 