NAME     = Animal
CXX      = c++
CXXFLAGS = -I include -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongAnimal.cpp src/Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re