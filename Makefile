# Output binary name
NAME = fractol

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx_opengl
MLX_LIB = $(MLX_DIR)/libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit

# Source and object files
SRCS = main.c utils.c utils2.c mandelbrot.c
OBJS = $(SRCS:.c=.o)

# Rules
all: $(MLX_LIB) $(NAME)

# Build the MiniLibX library in its directory
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Compile object files
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

# Link the final executable with the required libraries and frameworks
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_LIB) $(FRAMEWORKS) -o $(NAME)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

# Clean object files and the binary
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
