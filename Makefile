
NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    @$(CC) $(CFLAGS) -c $(SRCS)
    @ar rc $(NAME) $(OBJS)
    @ranlib $(NAME)
    @echo "Compilado: $(NAME)"

clean:
    @rm -f $(OBJS)
    @echo "Archivos objeto eliminados"

fclean: clean
    @rm -f $(NAME)
    @echo "Archivos binarios eliminados"

re: fclean all

