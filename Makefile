NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
LIBRARY = ar rc

SRCS = 

OBJS = $(SRCS:.c=.o)

INCLUDE = 

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(LIBRARY) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all