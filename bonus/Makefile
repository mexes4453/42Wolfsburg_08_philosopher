# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/09/11 21:34:20 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)
#SRCS:= main.c app_a_utils.c app_b_utils.c app_c_utils.c app_d_utils.c
# NOTE : the line above is the src for the mandatory part
SRCS:= main.c app_a_utils.c app_b_utils.c app_c_utils.c

SRCS_BONUS:= main_bonus.c queue_utils_bonus.c \
		map_a_utils_bonus.c map_b_utils_bonus.c map_c_utils_bonus.c \
		map_d_utils_bonus.c \
		nav_a_utils_bonus.c nav_b_utils_bonus.c \
		app_a_utils_bonus.c app_b_utils_bonus.c app_c_utils_bonus.c \
		app_d_utils_bonus.c app_e_utils_bonus.c \
		app_f_utils_bonus.c app_g_utils_bonus.c app_h_utils_bonus.c \


OBJS_BONUS:=$(SRCS_BONUS:.c=.o)
OBJS:= $(SRCS:.c=.o)

NAME = philo
#USR_LIB = libft.a
#USR_LIB_PATH = ./libft

CC = cc
#CFLAGS = -Werror -Wall -Wextra -O3 -g #-fsanitize=address
CFLAGS = -Werror -Wall -Wextra 
#	LIBFLAGS_STATIC = -L$(USR_LIB_PATH) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#	INCLUDES = -I./ -I$(USR_LIB_PATH) -Imlx_linux 
LIBFLAGS_STATIC =  -lpthread -pthread
INCLUDES = -I./ 

NAME : all
all : $(NAME)
$(NAME) : $(OBJS) 
	@echo "\033[1;33mCompiling Executables: ${NAME} \033[0m"
	$(CC) $^ $(LIBFLAGS_STATIC) $(CFLAGS) $(INCLUDES) -o $@
	@echo; echo "\033[1;32mCompilation Successful. \033[0m"
	@echo; echo

	
bonus: $(USR_LIB) $(OBJS_BONUS)
	@echo # line spacing
	@echo "\033[1;33mCompiling BONUS - SO_LONG \033[0m"
	rm -rf $(OBJS) > /dev/null
	$(CC) $^ $(LIBFLAGS_STATIC) $(CFLAGS) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32mCompilation Successful. \033[0m"


# obj files output
%.o : %.c
	@echo
	@echo "\033[1;33mCompiling OBJ files \033[0m"
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo


$(USR_LIB) :
	@echo
#	$(AR) $(LIBFLAGS_STATIC) $@ $^						# create the library file for linking
	@echo "\033[1;33mCompiling LIBFT Library \033[0m"
	cd ./libft; make > /dev/null; cp libft.a ../; cd ..	
	@echo												# print new line on screen

	

# remove all object files
fclean:
	rm -rf *.o

# remove final target files
clean: fclean
	rm -rf $(NAME)

# recompile everything
re: clean all

.PHONY : all fclean clean re 
