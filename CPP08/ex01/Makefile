# Source Files
SRCS = main.cpp Span.cpp

# Source Files Prefix
SRCS := $(addprefix src/, $(SRCS))

# Include Folder
INCLUDES = ./include

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Program Name
NAME = $(shell basename $(CURDIR))

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)

# Remove Command
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug: CXXFLAGS += -g -fsanitize=address
debug: fclean all

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
