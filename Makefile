SRC = ft_putendl_fd.c main.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
NAME = fractol

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

all : $(NAME)

bonus : all

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean all bonus clean
