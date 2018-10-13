# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avishnev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 14:48:02 by avishnev          #+#    #+#              #
#    Updated: 2018/03/21 14:48:03 by avishnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
FLAG = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror -o3 -o $(NAME)
LIB = ./libft/
SRC = srcs/main.c \
			srcs/fractal_calculate.c \
			srcs/fractal_calculate1.c \
			srcs/fractal_color_functions.c \
			srcs/fractal_controlers.c \
			srcs/fractal_gui.c \
			srcs/fractal_multithread.c \
			srcs/fractal_start.c \
			srcs/fractal_tools.c \
			srcs/fractal_tools1.c
INC = ./include
OBJ	= $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIB) --silent
	@gcc $(FLAG) $(SRC) $(LIB)libft.a -I $(INC)
	@gcc -o $(NAME) $(OBJ) $(LIBS) $(LIB)libft.a -I $(INC) $(FLAG)
	@echo "<<<<<<<<<<<<<<<<--Fractol_COMPILED-->>>>>>>>>>>>>>>>"
norm:
	@norminette ./srcs/
	@norminette ./include/
clean:
	@make -C $(LIB) clean --silent
	@rm -f srcs/*.o
	@echo "<<<<<<<<<<<<<<<<--Succes-->>>>>>>>>>>>>>>>"
fclean: clean
	@make -C $(LIB) fclean --silent
	@rm -f $(NAME)
re: fclean all