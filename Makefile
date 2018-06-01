# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohosla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 18:52:49 by obohosla          #+#    #+#              #
#    Updated: 2017/05/13 18:53:00 by obohosla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

SRCS = column.c \
	   error_opendir.c \
	   free.c \
	   get_stat.c \
	   main.c \
	   parsing_flg.c \
	   print.c \
	   sort_rsize.c \
	   sort_save.c \
	   sort_size.c \
	   sort_time.c \
	   with_arg.c
OBJ = $(SRCS:.c=.o)

LIBFTDIR = srcs/libft/

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) -I $(INCLUDES)/ft_ls.h -I srcs/libft/ft_printf.h $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libft.a:
	make -C srcs/libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)

re: clean all

norm:
	norminette srcs/ includes/*.h
