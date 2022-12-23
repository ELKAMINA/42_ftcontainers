NAME = container
	
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra #-std=c++98
CPPFLAGS = -MMD -I .

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o  $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean 
	make all

-include $(DEPS)
.PHONY : all clean fclean ree