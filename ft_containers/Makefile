NAME = container
	
SRC = main.cpp

MAVAR =  -DMAVAR=0

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD -I .

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o  $(NAME) $(OBJ)

diff:
	make re NAME='std_container' MAVAR='-DMAVAR=1'

clean :
	rm -rf $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean 
	make all

-include $(DEPS)
.PHONY : all clean fclean re diff