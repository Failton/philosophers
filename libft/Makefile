# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruthann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/04 21:28:43 by pruthann          #+#    #+#              #
#    Updated: 2020/11/15 16:39:40 by pruthann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalnum.c ft_memccpy.c ft_memcpy.c ft_strlen.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_isascii.c ft_memchr.c ft_memmove.c ft_tolower.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strncmp.c ft_strdup.c ft_calloc.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strlcpy.c ft_split.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

LIB	= libft.h

NAME	= libft.a

CC	= gcc

RM	= rm -f

AR	= ar rc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I/${LIB} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	${AR} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean:	clean
	${RM} ${NAME} 

re:	fclean all

bonus:	${OBJS} ${OBJS_B}
	${AR} ${NAME} ${OBJS} ${OBJS_B}

so:	${OBJS} ${OBJS_B}
	gcc -shared -o libft.so ${OBJS} ${OBJS_B}

.PHONY:	all clean fclean re bonus
