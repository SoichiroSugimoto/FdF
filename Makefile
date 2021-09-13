NAME		= fdf

SRCS		= ${shell find ./srcs/*.c}

OBJS		= $(SRCS:.c=.o)

HEADER		= ${shell find ./include/*.h}

MLX_HEADER	= ./mlx/mlx.h

LIBFT		= ./libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

ifeq ($(shell uname), Darwin)
	MLX_DIR		=	minilibx_macos/
	MLX		=	$(MLX_DIR)libmlx.a
	MLX_FLAGS		=	-framework OpenGL -framework AppKit
else
	MLX_DIR		=	minilibx-linux/
	MLX		=	$(MLX_DIR)libmlx_Linux.a
	MLX_FLAGS		=	-lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) srcs/*.c libft/*.c -o $(NAME) mlx/libmlx.a $(MLX_FLAGS)

$(LIBFT) :
	make -C libft

$(MLX) :
	make -C mlx

$(OBJS) :


clean :
	rm -f $(OBJS)
	make clean -C libft
	make clean -C mlx

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C mlx

re : fclean all

.PHONY : all clean fclean re