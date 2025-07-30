# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:49:53 by yriffard          #+#    #+#              #
#    Updated: 2025/07/30 11:52:49 by tgodefro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXE = bsq

CC = cc -g

CFLAGS = -Wall -Wextra -Werror -I includes/


MY_SOURCES = srcs/main.c srcs/ft_parse_map.c srcs/map_checking.c srcs/map_file_reading.c \
			srcs/utils/ft_utils.c srcs/utils/ft_utils2.c srcs/utils/ft_array_utils.c \
			srcs/utils/ft_split.c srcs/utils/ft_atoi.c

OBJDIRCREATE := $(shell mkdir -p objs/srcs/utils)
OBJDIR = objs/
OBJECTS = $(MY_SOURCES:.c=.o)

all : $(EXE)

$(EXE) : $(addprefix $(OBJDIR),$(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(addprefix $(OBJDIR),$(OBJECTS))

fclean : clean
	rm -f $(EXE)

re : fclean all

.PHONY : all clean fclean re
