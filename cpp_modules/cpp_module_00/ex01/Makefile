NAME = phonebook

FLAGS = -Werror -Wall -Wextra

SRCS = contact.cpp main.cpp phonebook.cpp

OBJS = $(SRCS:%.cpp=%.o)

INC = contact.hpp

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