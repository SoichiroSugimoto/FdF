NAME		= fdf

SRCS_DIR	= srcs/

SRCS		=	draw_utils.c \
				draw_utils2.c \
				draw.c \
				error_deal.c \
				free.c \
				init.c \
				main.c \
				read_file_utils.c \
				read_file_utils2.c \
				read_file_utils3.c \
				read_file.c \
				replace.c

OBJ_FILES	= $(SRCS:.c=.o)

OBJ_DIR		= objs/

OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADER		= ./includes/fdf.h

MLX_HEADER	= ./mlx/mlx.h

LIBFT		= ./libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

HEADERS		=	includes/ $(MLX_DIR)/ libft/includes
INCLUDES	=	$(addprefix -I, $(HEADERS))

ifeq ($(shell uname), Darwin)
	MLX_DIR		=	mlx_macos/
	MLX			=	$(MLX_DIR)libmlx.a
	MLX_FLAGS	=	-framework OpenGL -framework AppKit
else
	MLX_DIR		=	mlx_linux/
	MLX			=	$(MLX_DIR)libmlx_Linux.a
	MLX_FLAGS	=	-lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(INCLUDES)

$(LIBFT) :
	make -C libft

$(MLX) :
	make -C $(MLX_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(INCLUDES) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)
	make clean -C libft
	make clean -C $(MLX_DIR)

fclean : clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C libft
	make clean -C $(MLX_DIR)

re : fclean all

.PHONY : all clean fclean re
