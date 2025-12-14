
# Source Files
SRCS = main.cpp Bureaucrat.cpp

# Source Files Prefix
SRCS := $(addprefix src/, $(SRCS))
# Include Folder
INCLUDES = "./include"

# Objects Files
OBJS = $(SRCS:.cpp=.o)

# Name Of The Compiled Program
NAME = $(shell basename $(CURDIR))

# Compilation Program
CXX = c++
# Compilation Flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)

# Remove Files Command
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug: CXXFLAGS += -g -fsanitize=address
debug: fclean $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
