NAME = fdf

INC_DIR	=	./inc/

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HEAD	=	$(LIBFT_DIR)inc/

MLX_DIR		=	./minilibx_macos/
MLX_HEAD	=	$(MLX_DIR)
MLX			= 	$(MLX_DIR)libmlx.a

LIBRARIES	=	-lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES	=	-I$(LIBFT_HEAD) -I$(MLX_HEAD) -I$(INC_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

test: $(MLX) $(LIBFT)
	gcc $(LIBRARIES) $(INCLUDES) main.c -o $(NAME)