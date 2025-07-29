
cc -Wall -Wextra -Werror -c ft_putchar.c -o ft_putchar.o
cc -Wall -Wextra -Werror -c ft_putstr.c -o ft_putstr.o
cc -Wall -Wextra -Werror -c ft_strcmp.c -o ft_strcmp.o
cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o
cc -Wall -Wextra -Werror -c ft_swap.c -o ft_swap.o
ar ruv libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
