# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yriffard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:49:53 by yriffard          #+#    #+#              #
#    Updated: 2025/07/28 09:52:34 by yriffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

MY_SOURCES = 

OBJECTS = $(MY_SOURCES:.c=.o)

all : $(EXE)

$(EXE) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(COMPILED)

re : fclean all

.PHONY : all clean fclean re
