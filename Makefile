# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/09/25 09:03:41 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS:= main.c ft_app_atoi.c ft_app_chk_input.c ft_app_var_init.c \
		ft_app_sleep.c \
		ft_app_eat.c ft_app_think.c ft_app_live.c ft_app_timestamp.c  		\
		ft_app_count_eat.c ft_app_is_philo_starved.c ft_app_fork_mtx_lock.c	\
		ft_app_fork_mtx_unlock.c ft_app_fork_lim_chk.c \
		ft_app_malloc_thr_mtx_var_ptrs.c ft_app_init_thr_mtx_var_ptrs.c \
		ft_app_create_thrds.c ft_app_threads_rejoin.c \
		ft_app_free_mem.c ft_app_sleep_timer.c ft_app_clk_diff_ms.c \
		ft_app_stdout.c \
		ft_app_detect_death.c ft_atm_rw.c\
		queue_utils.c


OBJS:= $(SRCS:.c=.o)

NAME = philo

CC = cc
CFLAGS = -Werror -Wall -Wextra #-fsanitize=thread -g
LIBFLAGS_STATIC =  -lpthread -pthread
INCLUDES = -I./ 

NAME : all
all : $(NAME)
$(NAME) : $(OBJS) 
	@echo "\033[1;33mCompiling Executables: ${NAME} \033[0m"
	$(CC) $^ $(LIBFLAGS_STATIC) $(CFLAGS) $(INCLUDES) -o $@
	@echo; echo "\033[1;32mCompilation Successful. \033[0m"
	@echo; echo

	
# obj files output
%.o : %.c
	@echo
	@echo "\033[1;33mCompiling OBJ files \033[0m"
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo


# remove all object files
fclean:
	rm -rf *.o

# remove final target files
clean: fclean
	rm -rf $(NAME)

# recompile everything
re: clean all

.PHONY : all fclean clean re 

# to debug thread execution please include the following flags with valgrind
# ./valgrind --tool=helgrind --read-var-info=yes ./philo 5 800 200 200 5
