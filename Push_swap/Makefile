# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2023/03/01 14:41:44 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS_NAME	=	checker
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -rf
MKDIR		=	mkdir -p
CFLAGS		=	-Wall -Wextra -Werror
SRCS_FILES	=	ps_main_bonus \
				ps_getters_bonus \
				ps_getters2_bonus \
				ps_sortsmall_bonus \
				ps_operators_bonus \
				ps_sorthundred_bonus
BONUS_FILES	=	checker_main_bonus \
				checker_getters_bonus \
				checker_getters2_bonus \
				checker_operators_bonus
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS_SRCS	=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJS	=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/
BONUS_DIR	=	bonus/

all:			
				$(MKDIR) $(OBJS_DIR)
				make libft $(NAME)

bonus:
				$(MKDIR) $(OBJS_DIR)
				make libft $(BONUS_NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

$(BONUS_NAME):	$(BONUS_OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(BONUS_OBJS) -o $(BONUS_NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME) $(BONUS_NAME)

re:				fclean all

.PHONY:			all bonus libft clean fclean re