# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:47:35 by igrousso          #+#    #+#              #
#    Updated: 2026/06/15 19:47:35 by igrousso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = nasm

FLAGS += -f elf64
DEBUG ?=

NAME = libasm.a

EXEC = executable

MAIN = main.c

SRC = ft_strlen.s \
	  ft_strcpy.s \
	  ft_strcmp.s \
	  ft_write.s \
	  ft_read.s \
	  ft_strdup.s \
	  ft_atoi_base.s

OBJ = $(SRC:.s=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $@ $^

%.o : %.s
	$(CC) $(FLAGS) $< -o $@

exec : $(NAME)
	cc $(MAIN) $^ -o $(EXEC) $(DEBUG)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(EXEC)

re : fclean all

.PHONY : all clean fclean re