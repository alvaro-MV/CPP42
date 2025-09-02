CXX:=c++
CXXFLAGS:=-Wall -Wextra -Werror -std=c++98
NAME:=fixed
SRCS:= main.cpp Fixed.cpp Point.cpp bsp.cpp nodeLine.cpp
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