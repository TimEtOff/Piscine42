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

CFLAGS = -Wall -Wextra -Werror -I srcs/

MY_SOURCES = srcs/main.c srcs/ft_parse_map.c srcs/map_checking.c srcs/map_file_reading.c \
			srcs/utils/ft_utils.c srcs/utils/ft_utils2.c srcs/utils/ft_array_utils.c \
			srcs/utils/ft_split.c srcs/utils/ft_atoi.c srcs/utils/ft_strdup.c

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
