NAME = game

SRCS = main.c\
	./parsing/check-colors.c\
	./parsing/check-components.c\
	./parsing/check-keys.c\
	./parsing/check-map.c\
	./parsing/check-paths.c\
	./parsing/check-textures.c\
	./parsing/error.c\
	./parsing/get-colors.c\
	./parsing/gnl.c\
	init-parse.c\
	./parsing/is-valid-path.c\
	./parsing/player-pos.c\
	./parsing/str-colors.c\
	./parsing/tools.c\
	./raycasting/utils.c\
	./raycasting/initgame.c\

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -g3 $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
