CXX:=c++
CXXFLAGS:= -g -Wall -Wextra -Werror -std=c++98
NAME:=converter
SRCS:=  ScalarConverter.cpp main.cpp  print_scalar.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re