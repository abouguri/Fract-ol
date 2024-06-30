SRC = ft_putendl_fd.c main.c ft_strcmp.c events.c tools.c maths_tools.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext
NAME = fractol



all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean all  clean
