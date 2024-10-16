NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx_opengl
MLX_LIB = $(MLX_DIR)/libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit
LINUX = -lXext -lX11 -lm -lz

SRCS = main.c utils.c utils2.c utils3.c mandelbrot.c events.c julia.c burning_ship.c
OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_LIB) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
