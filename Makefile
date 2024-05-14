LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

USER		= paromero
SRCS		= src/map.c src/map_checker.c src/ft_free.c src/main.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I ./libft -I/opt/X11/include -IMLX42
MLX42 = ./MLX42
LIBFT		= libft/libft.a
LIBS		= -L./libft -lft
MLX_FLAGS = -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

NAME = so_long

# Colores
#
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling objects...$(RESET)"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C $(MLX42) clean
	@$(RM) $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C $(MLX42) fclean
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re