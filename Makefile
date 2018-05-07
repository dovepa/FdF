# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 12:54:37 by dpalombo          #+#    #+#              #
#    Updated: 2018/05/07 14:05:00 by dpalombo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCLIBFT = libft
SRCMLX = minilibx_macos
SRC = fichiers c ici

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -c $? -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C $(SRCLIBFT)
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)
	@echo "ok prog"

clean:
	@$(MAKE) clean -C $(SRCLIBFT)
	@/bin/rm -f $(OBJ)
	@echo "supp obj ok"

fclean: clean
	@$(MAKE) fclean -C $(SRCLIBFT)
	@/bin/rm -f $(NAME)
	@echo "sup + prog ok"

re: fclean all

.PHONY = all clean fclean re