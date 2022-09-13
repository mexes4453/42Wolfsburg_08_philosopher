/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_const.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:15:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/12 21:40:42 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPE_CONST_H
# define DATATYPE_CONST_H
# define USEC   (1000000)
# define MSEC   (1000)
# define PATH_SEM ("/sem_fork")
# define PATH_SEM_PRINT ("/sem_print")
# define SEM_PRINT_INIT (1)
# define ERR_PHILO_EAT_LIMIT (-1)
# define ERR_PHILO_STARVED (-2)
# define ERR_PHILO_FORK_LIMIT (-3)

typedef struct s_app
{
	int				rc;
	int				nbr_philo;
	int				nbr_fork;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				nbr_eat;
	int				rc_eat;
	int				cnt_thr_eat;
	sem_t	*sem_forks;
	sem_t	*sem_print;
	pthread_mutex_t	*mtx_forks;
}					t_app;

typedef struct s_threadvar
{
	int				id;
	int				cnt_eat;
	struct timeval	clk_start;
	struct timeval	clk_eat;
	struct timeval	now;
	struct timeval	time_diff;
	suseconds_t		ts_ms;
	t_app			*a_var;
}					t_threadvar;
#endif
