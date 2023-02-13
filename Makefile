# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imahri <imahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 23:28:40 by imahri            #+#    #+#              #
#    Updated: 2023/01/03 20:57:21 by imahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker
CC = cc
HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror
SRC =	linkee.c\
		ft_swap.c\
		linke.c\
		ft_push.c\
		ft_rev_rotate.c\
		ft_rotate.c\
		push_swap_b.c\
		push_swap_a.c\
		submit.c\
		utils_push_swap.c\
		ft_split.c\
		ft_push_swap.c\
		push_tree.c\
		submitt.c

MSRC =	main.c\
		${SRC}

BSRC =	get_next_line_utils.c\
		get_next_line.c\
		my_checker.c\
		my_checker_utils.c\
		${SRC}

OBJ = ${MSRC:.c=.o}
BOBJ = ${BSRC:.c=.o}

all: ${NAME}

${NAME} : ${OBJ}
	$(CC)  -o ${NAME} ${OBJ}

%.o : %.c $(HEADER)
	${CC} ${FLAGS} -c $<

bonus : $(BOBJ)
	$(CC)  -o ${BNAME} ${BOBJ}

clean :
	rm -f ${OBJ}
	rm -f ${BOBJ}

re: fclean all

fclean : clean
	rm -f ${NAME} ${BNAME}

.PHONY : all clean fclean re