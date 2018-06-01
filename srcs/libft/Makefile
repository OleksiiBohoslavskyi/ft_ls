# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohosla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 11:19:52 by obohosla          #+#    #+#              #
#    Updated: 2017/05/13 17:12:35 by obohosla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft.h

OBJECTS = ft_strlen.o ft_bzero.o ft_memset.o ft_memcpy.o ft_memccpy.o\
		  ft_memmove.o ft_memchr.o ft_memcmp.o ft_strdup.o ft_strcpy.o\
		  ft_strncpy.o ft_strcat.o ft_strcat.o ft_strncat.o ft_strlcat.o\
		  ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o\
		  ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o\
		  ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o\
		  ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o\
          ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o\
          ft_strnequ.o ft_strsub.o ft_strjoin.o ft_putchar.o ft_putstr.o\
		  ft_putendl.o ft_putnbr.o ft_itoa.o ft_strtrim.o ft_strsplit.o\
          ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
		  ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o\
		  ft_lstnew.o\
		  ft_strndup.o ft_count_n.o ft_strrev.o ft_swap.o ft_arrdel.o\
		  ft_strrev.o ft_lstlen.o\
		  get_next_line.o \
		  fpf_sc.o fpf_clc.o fpf_p.o fpf_xx2.o fpf_xx.o fpf_uu.o fpf_s.o \
		  fpf_oo.o fpf_c.o fpf_idd2.o fpf_idd.o fpf_vyvid.o fpf_parsing2.o \
		  fpf_parsing.o fpf_color.o fpf_patoiuu.o ft_printf.o fpf_atoi.o
all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : clean	all
