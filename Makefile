CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

MANDATORY_SRCS = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_itoas.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
HEADER = ft_printf.h

all: $(NAME)
$(NAME): $(MANDATORY_OBJS)
	ar rc $(NAME) $(MANDATORY_OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

