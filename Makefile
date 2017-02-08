# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 17:26:44 by nsabbah           #+#    #+#              #
#    Updated: 2017/02/08 18:19:59 by nsabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_A = ./fd_push_swap
LIB_B = ./fd_checker

MY_TARGETS = $(LIB_A) $(LIB_B)

.PHONY: all
all: $(MY_TARGETS)

.PHONY: $(LIB_A)
$(LIB_A):
	@$(MAKE) -C $@;

.PHONY: $(LIB_B)
$(LIB_B):
	@$(MAKE) -C $@;

clean:
	make clean -C $(LIB_A)
	make clean -C $(LIB_B)

fclean:
	make fclean -C $(LIB_A)
	make fclean -C $(LIB_B)

re: fclean all
