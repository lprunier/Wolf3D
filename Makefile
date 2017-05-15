NAME = wolf3d

SRC =	main.c\
		play.c\
		init.c\
		image.c\
		check.c\
		draw.c\
		wall.c\

CFILES = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

INCLUDE = -I include/ -I minilibx_macos/ -I libft/

FLAG = -Wall -Wextra -Werror

LIB = -lft -L libft/ -L ./minilibx_macos -lmlx -framework OPENGL -framework AppKit

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(CFILES)
	@make -C libft/ fclean && make -C libft && make -C libft/ clean
	@gcc -o $(NAME) $(LIB) $(OBJ)
	@mkdir obj && mv $(OBJ) obj/
	@echo "\033[32mCompilation of Wolf3d.\033[0m"

clean:
	@/bin/rm -rf obj
	@echo "\033[33mClean of Wolf3d.\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo "\033[31mFull cleaning of Wolf3d.\033[0m"

re: 	fclean all
	@echo "\033[32mFull cleaning and recompilation of Wolf3d.\033[0m"
	@make -C libft/ fclean

.PHONY: all, clean, fclean, re
