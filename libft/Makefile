# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndombre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 09:47:44 by ndombre           #+#    #+#              #
#    Updated: 2016/11/14 17:01:45 by ndombre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src=ft_memrplchr.c ft_atoi.c ft_bzero.c ft_free.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_malloc.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c ft_print_memory.c ft_putbasse.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_puterrl.c ft_puthex.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strntest.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtest.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_write.c
NAME=libft.a

obj=$(src:.c=.o)

all: $(NAME)

$(NAME): $(obj)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	gcc -Wall -Werror -Wextra -I. -o $@ -c $<

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette *.c
	norminette *.h

gc:
	echo *.c
