# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/30 17:20:13 by jukim             #+#    #+#              #
#    Updated: 2018/05/12 22:46:56 by jukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFILES = main.c setting.c fractol_sets.c
OFILES = $(CFILES:.c=.o)
SRC = $(addprefix src/, $(CFILES))
MLX = src/minilibx_macos
LIBFT = src/libft
CFLAGS = -I. -I $(MLX) -I $(LIBFT) -Wall -Wextra -Werror
LFLAGS = -L $(LIBFT) -lft
MFLAGS = -L $(MLX) -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@make -C $(MLX)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(CFLAGS) $(LFLAGS) $(MFLAGS) $(OFILES) -o $(NAME)
	@echo "\033[0;31m\033[1m\(>ㅠ<)/"

clean:
	@/bin/rm -f $(OFILES)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)
	@/bin/rm -f $(NAME)

re: fclean all
