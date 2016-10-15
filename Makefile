#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 15:44:42 by nbrizini          #+#    #+#              #
#    Updated: 2016/02/25 16:17:38 by nbrizini         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

SRC_NAME = main.c draw.c hook.c wolf.c ft_mlx_xpm.c

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/

LIB_PATH = ./libft/

LIB_NAME = libft.a

MINI_LIB = -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

COMPILE = echo "\033[36mCompile ...."
COMPILED = echo "\033[32mCompiled Successfully"
CLEAN = echo "\033[38mClean ...."
CLEANED = echo "\033[32mCleaned Successfully"

all: libmake $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(COMPILE)
	@$(CC) $(CFLAGS) -L$(LIB_PATH) -o $(NAME) -I$(INC_PATH) $(MINI_LIB) \
		$(LIB) $(OBJ)
	@$(COMPILED)

libmake:
	@(make -C libft/)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CC) $(CFLAGS) -o $@ -I$(INC_PATH) -c $<

clean: libclean
	@$(CLEAN)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CLEANED)

libclean:
	@(make -C libft/ clean)

fclean: clean libfclean
	@rm -f $(NAME)

libfclean:
	@(make -C libft/ fclean)

re: fclean all
