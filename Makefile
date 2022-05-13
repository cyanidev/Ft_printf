# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 19:14:50 by afelicia          #+#    #+#              #
#    Updated: 2022/05/13 15:01:39 by afelicia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c ft_printfutils.c print_type.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re

#-c      Whenever an archive is created, an informational message to that effect is 
#written to standard error.  If the -c option is specified, ar creates the archive silently.

#-r      Replace or add the specified files to the archive.  If the archive does not exist 
#a new archive file is created.  Files that replace existing files do not change the order of the files within the archive. 
# New files are appended to the archive unless one of the options -a, -b or -i is specified.

#-s      Write an object-file index into the archive, or update an existing one, even if no other change is made to the archive. 
# You may use this modifier flag either with any operation, or alone.  Running `ar s' on an archive is equivalent to running `ranlib' on it.