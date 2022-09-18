/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_const.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:15:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 00:37:19 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPE_CONST_H
# define DATATYPE_CONST_H
# define USEC   (1000000)
# define MSEC   (1000)
# define ERR_PHILO_EAT_LIMIT (-1)
# define ERR_PHILO_STARVED (-2)
# define ERR_PHILO_FORK_LIMIT (-3)
# define ERR_GET_TIME_OF_DAY (-4)

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
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_rc;
	pthread_mutex_t	mtx_print;
}					t_app;

typedef struct s_threadvar
{
	int				rc;
	int				id;
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
}					t_threadvar;
#endif
