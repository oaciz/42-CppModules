NAME	= RPN

SOURCES	= main.cpp RPN.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC		= c++ -g
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all