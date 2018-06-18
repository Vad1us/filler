# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vradchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 16:42:47 by vradchen          #+#    #+#              #
#    Updated: 2018/04/27 16:42:48 by vradchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		vradchen.filler

FLAGS =		-Wall -Wextra -Werror
H =			./filler.h

OPT =		-c -I $(H)

SOURCES =	./ft_check.c ./ft_closest.c ./ft_filler.c ./ft_roadtozero.c\

OBJ = 		$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OPT) $(SOURCES)
	@make -C ./libft/
	@make -C ./libft/printf
	@gcc -o $(NAME) $(FLAGS) $(OBJ) ./libft/libft.a ./libft/printf/libftprintf.a

clean:
	@make clean -C ./libft/
	@make clean -C ./libft/printf
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft/
	@make fclean -C ./libft/printf
	@rm -rf $(OBJ)

re: fclean all