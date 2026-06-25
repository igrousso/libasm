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

ADEBUG ?=
CDEBUG ?=

FLAGS += -f elf64 $(ADEBUG)

NAME = libasm.a

EXEC = executable

MAIN = main.c

SRC = ft_strlen.s \
	  ft_strcpy.s \
	  ft_strcmp.s \
	  ft_write.s \
	  ft_read.s \
	  ft_strdup.s \
	  ft_atoi_base.s \
	  ft_list_push_front.s \
	  ft_list_size.s \
	  ft_list_sort.s \
	  ft_list_remove_if.s

OBJ = $(SRC:.s=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $@ $^

%.o : %.s
	$(CC) $(FLAGS) $< -o $@

exec : $(NAME)
	cc $(MAIN) $^ -o $(EXEC) $(CDEBUG)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(EXEC)

re : fclean all

.PHONY : all clean fclean re