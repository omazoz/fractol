# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:27:23 by omazoz            #+#    #+#              #
#    Updated: 2022/02/24 22:55:30 by omazoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

INCLUDE = $(INC_DIR)/fractol.h

INCLUDES = $(INC_DIR)/fractol.h\
		   $(INC_DIR)/ft_mlx_keys.h

SRC = main.c\
	  events.c\
	  init.c\
	  mandelbrot.c\
	  images.c\
	  julia.c

SRC_B = main.c\
		mandelbrot.c\
		julia.c

OBJ = $(addprefix $(OBJ_DIR)/, ${SRC:.c=.o})
OBJ_B = $(addprefix $(OBJ_DIR)/, ${SRC_B:.c=.o})

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -I ./libft

LIBFT = ./libft/libft.a

BLUE=\033[0;34m

ORANG=\033[0;33m

RESET=\033[0m

CC = cc

all : $(NAME) | fractal_art

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I $(INC_DIR) -I libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME) : $(LIBFT) $(OBJ) $(INCLUDES)
			@$(CC) $(CFLAGS) $(OBJ) -I $(INC_DIR) -o $(NAME)

$(LIBFT) :
	make -C ./libft

bonus: $(OBJ_B) $(INCLUDE) | fractal_art
	gcc $(CFLAGS) $(OBJ_B) -o $(NAME)_bonus
	@echo "BONUS IS READY";

clean :
	@make -C ./libft clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: fractal_art

fractal_art:
	@echo "$(BLUE)";
	@echo "███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗     ";
	@echo "██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║     ";
	@echo "█████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║     ";
	@echo "██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║     ";
	@echo "██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗";
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝";
	@echo "$(RESET)"
	@echo "                                                       ";
	@cat fractal.ascii
