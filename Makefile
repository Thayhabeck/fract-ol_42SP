# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 01:45:17 by thabeck-          #+#    #+#              #
#    Updated: 2022/08/17 01:45:20 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCS		= 	main.c 						\
				./source/arguments.c		\
				./source/color.c			\
				./source/fractol_utils.c	\
				./source/fractol.c			\
				./source/hooks.c			\
				./source/julia.c			\
				./source/starjulia.c		\
				./source/mandelbrot.c		\
				./source/color_rgb.c		\
				./source/logs.c				\
				

HDRS		= 	./includes/fractol.h		\
				./includes/defines.h		\
				./includes/structs.h		\

OBJS		= ${SRCS:.c=.o}

RM			= rm -f
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
MLX			= /usr/local/lib/libmlx.a
MLX_FLAGS	= -lXext -lX11 -lmlx -lm
LIBFT		= ./libft/libft.a

LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fractol

PURPLE		= \033[0;35m
RESET		= \033[0m

all: $(NAME)

.c.o:
		@echo "\n$(PURPLE)object file [$(<:.c=.o)] was created$(RESET)"
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(MLX):
		make -C ./minilibx-linux
$(LIBFT):
		make -C ./libft

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(HDRS)
		@echo "\n$(PURPLE)$(NAME) was created$(RESET)"
		$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

bonus: $(NAME)

leaks: $(NAME)
	$(LEAKS) $(LF)

norm:
	norminette ${SRCS} ${HDRS}

clean:
		@echo "$(PURPLE)object files were deleted$(RESET)"
		make -C ./libft clean
		$(RM) $(OBJS) $(LEAKS_FILE)

fclean:	clean
		@echo "\n$(PURPLE)$(NAME) was deleted$(RESET)"
		make -C ./libft fclean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re norm leaks
