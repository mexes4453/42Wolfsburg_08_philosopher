/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_const.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:15:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 09:10:23 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPE_CONST_H
# define DATATYPE_CONST_H
# define USEC (1000000)
# define MSEC (1000)
# define ERR_PHILO_EAT_LIMIT (-1)
# define ERR_PHILO_STARVED (-2)
# define ERR_PHILO_FORK_LIMIT (-3)
# define ERR_GET_TIME_OF_DAY (-4)
# define ERR_PHILO_DIED (-5)
# define FORK_TAKEN (0)
# define FORK_FREE (1)
# define SCAN_DELAY (10)
# include "queue_utils.h"

typedef enum e_state
{
	DEAD,
	EAT,
	SLEEP,
	THINK,
	FULL
}	t_state;

typedef struct s_app
{
	int				rc;
	int				nbr_philo;
	suseconds_t		ts_ms;
	int				nbr_fork;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				nbr_eat;
	int				rc_eat;
	int				cnt_thr_eat;
	int				*forks_state;
	pthread_mutex_t	*mtx_forks_state;
	t_queue			*thrds_state;
	struct timeval	clk_n;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_rc;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_philo;
}					t_app;

typedef struct s_threadvar
{
	int				rc;
	int				id;
	t_state			state;
	int				locked_forks;
	int				nbr_eat;
	int				cnt_eat;
	int				time_die;
	int				time_eat;
	int				time_slp;
	struct timeval	clk_start;
	struct timeval	clk_eat;
	struct timeval	now;
	struct timeval	time_diff;
	suseconds_t		ts_ms;
	t_app			*a_var;
	pthread_mutex_t	mtx_state;
}					t_threadvar;
#endif
