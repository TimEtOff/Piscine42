# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yriffard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:49:53 by yriffard          #+#    #+#              #
#    Updated: 2025/07/28 15:03:33 by yriffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

MY_SOURCES = ft_array_utils.c \
		ft_split.c \
		ft_utils2.c \
		ft_utils.c \
		ft_atoi.c \
		ft_parse_map.c \
		main.c \
		map_checking.c \
		map_file_reading.c \
		

OBJECTS = $(MY_SOURCES:.c=.o)

all : $(EXE)

$(EXE) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(EXE)

re : fclean all

.PHONY : all clean fclean re
