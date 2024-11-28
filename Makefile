NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
LIBRARY = ar rc

SRCS = 	ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c \
		ft_puthex.c ft_putunbr.c ft_putdinbr.c

OBJS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

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

debug:
	$(CC) -g $(FLAGS) $(SRCS)