CC = cc
CFLAGS = -Wall -Wextra -Werror
# cc ft.c -Lmlx -lmlx -lXext -lX11 -lm -o fractol

MLX_EX = mlx
MLX_FLAG = -L$(MLX_EX) -lmlx -lXext -lX11 -lm

SRCs = fractol.c parse_utils.c mandel.c
OBJs = $(SRCs:.c=.o)

NAME = fractol

all: $(NAME)
$(NAME): $(OBJs)
	$(CC) $(CFLAGS) $(OBJs) $(MLX_FLAG) -o $(NAME)

clean:
	rm -f $(OBJs)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
