# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:49:53 by tgodefro          #+#    #+#              #
#    Updated: 2025/07/29 22:29:47 by tgodefro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXE = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes/

AR = ar rv

MY_SOURCES = srcs/ft_putchar.c srcs/ft_swap.c \
				srcs/ft_putstr.c srcs/ft_strlen.c \
				srcs/ft_strcmp.c

OBJECTS = $(MY_SOURCES:.c=.o)

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(AR) -o $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(EXE)

re : fclean all

.PHONY : all clean fclean re
