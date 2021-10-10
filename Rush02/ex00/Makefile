# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 23:11:01 by dperez-m          #+#    #+#              #
#    Updated: 2021/10/10 23:30:26 by hmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= r02_w.c main.c arranger.c extras.c ft_get_number.c ft_test_array.c ft_scale_name.c
OBJS	= ${SRCS: .c = .o}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= Rush-02
RM		= rm -f
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re