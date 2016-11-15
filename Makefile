# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndombre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 09:47:44 by ndombre           #+#    #+#              #
#    Updated: 2016/11/15 17:05:08 by narlati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src=solver.c put_letter.c check_tetri.c get_tetri.c lsttetri.c main.c make_tetri.c map.c normalise_tetri.c print_map.c print_tetri.c read_tetri.c
NAME=fillit

obj=$(src:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(obj)
	gcc -Wall -Werror -Wextra -Ilibft -I. -o $(NAME) $(obj) libft/libft.a

%.o: %.c
	gcc -Wall -Werror -Wextra -Ilibft -I. -o $@ -c $<

clean:
	rm -f $(obj)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean $(NAME)

libft/libft.a:
	make -C ./libft/

norm:
	norminette *.c
	norminette *.h

gc:
	echo *.c

s: fclean
	git status
