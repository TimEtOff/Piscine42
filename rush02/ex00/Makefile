# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlaponte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 18:08:23 by nlaponte          #+#    #+#              #
#    Updated: 2025/07/27 23:34:35 by mboutte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = cut.c ft_hundred.c ft_tens.c \
	ft_utils.c find.c ft_strdup.c \
	ft_strjoin.c ft_dictverif.c main.c \
	get_words.c

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(OBJ) 
	$(CC) $(Cflags) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: all
	./rush-02
