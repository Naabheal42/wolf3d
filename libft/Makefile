#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 18:33:07 by nbrizini          #+#    #+#              #
#    Updated: 2015/03/06 16:36:12 by nbrizini         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

INCLUDES = includes

SRC	= ft_atoi.c\
    ft_bzero.c\
    ft_isalnum.c\
    ft_isalpha.c\
    ft_isascii.c\
    ft_isdigit.c\
    ft_isprint.c\
    ft_memalloc.c\
    ft_memccpy.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_memcpy.c\
    ft_memdel.c\
    ft_memmove.c\
    ft_memset.c\
    ft_realloc.c\
    ft_putchar.c\
    ft_putchar_fd.c\
    ft_putendl.c\
    ft_putendl_fd.c\
    ft_putnbr.c\
    ft_putnbr_fd.c\
    ft_putstr.c\
    ft_putstr_fd.c\
    ft_strcat.c\
    ft_strchr.c\
    ft_strclr.c\
    ft_strcmp.c\
    ft_strcpy.c\
    ft_strdel.c\
    ft_strdup.c\
    ft_strequ.c\
    ft_striter.c\
    ft_striteri.c\
    ft_strjoin.c\
    ft_strlcat.c\
    ft_strlen.c\
    ft_strmap.c\
    ft_strmapi.c\
    ft_strncat.c\
    ft_strncmp.c\
    ft_strncpy.c\
    ft_strnequ.c\
    ft_strnew.c\
    ft_strnstr.c\
    ft_strrchr.c\
    ft_strstr.c\
    ft_strsub.c\
    ft_strpos.c\
    ft_tolower.c\
    ft_toupper.c\
    ft_itoa.c\
    ft_strtrim.c\
    ft_strsplit.c\
    ft_lstnew.c\
    ft_lstdelone.c\
    ft_lstdel.c\
    ft_lstadd.c\
    ft_lstiter.c\
    ft_lstmap.c\
		ft_strdupc.c\
		ft_strlenc.c\
		ft_strcpyc.c\
	get_next_line.c\

LIB = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
AR = ar rc
OBJ = $(SRC:.c=.o)
RM = rm -rf
RANLIB = ranlib

all: $(LIB)

$(LIB): $(OBJ)
	@echo "Creating Library...";
	@$(AR) $(LIB) $(OBJ)
	@echo "Done.";
	@echo "Indexing Library...";
	@$(RANLIB) $(LIB)
	@echo "Done.";

%.o: %.c
	@echo "Compiling $<";
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files...";
	@$(RM) $(OBJ)
	@echo "Done.";

fclean: clean
	@echo "Cleaning Library...";
	@$(RM) $(LIB)
	@echo "Done.";

re: fclean all

.PHONY: all clean fclean re
