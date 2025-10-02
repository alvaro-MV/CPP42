CXX:=c++
CXXFLAGS:=-Wall -Wextra -Werror -std=c++98
NAME:=interface
SRCS:= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

DEBUG = 0
ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re