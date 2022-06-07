# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 20:23:09 by gdominic          #+#    #+#              #
#    Updated: 2022/06/07 16:41:54 by gdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_strlen.c ft_putnbr.c ft_putstr.c \
	  ft_convertx.c ft_putnbr_u.c ft_ptr.c

OBJS = ${SRC:.c=.o} 
# OBJBONUS = ${SRCBONUS:.c=.o}

DEPS = ft_printf.h

%.o: %.c $(DEPS)
	${CC} ${CFLAGS} -I${DEPS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
#	$(MAKE) -s -C libft 
#	@cp libft/libft.a .
#	@mv libft.a $(NAME)
	@ar rcs $@ $^
	@echo Archive\ created!!

# bonus: ${OBJS} ${OBJBONUS} ${DEPS}
#	@ar rcs ${NAME} ${OBJS} ${OBJBONUS}
#	@touch $@
#	@echo Bonus done!!! Congrats!!

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f a.out
#	@rm -f ${OBJBONUS}

fclean: clean
	@/bin/rm -f $(NAME)
#	@rm -f bonus

re: fclean all

.PHONY: all clean fclean re
