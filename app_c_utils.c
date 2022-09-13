/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_c_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/10 22:13:27 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_c_utils.h"

/**
 * @brief 	This function used to implement the mutex lock for the forks.
 * 			Each thread (philosopher) must lock the mutex of two forks.
 * 			They must secure the forks adjacent to them.
 * 
 * @param t_var 
 */
void	ft_app_fork_mtx_lock(t_threadvar *t_var)
{
	pthread_mutex_t	*mtx_fks;
	int				fk_r;
	int				fk_l;

	mtx_fks = t_var->a_var->mtx_forks;
	fk_r = (t_var->id) % (t_var->a_var->nbr_fork);
	fk_l = (t_var->id - 1) % (t_var->a_var->nbr_fork);
	if (t_var->id % 2 == 1)
	{
		pthread_mutex_lock(&(mtx_fks[fk_l]));
		pthread_mutex_lock(&(mtx_fks[fk_r]));
	}
	else
	{
		pthread_mutex_lock(&(mtx_fks[fk_l]));
		pthread_mutex_lock(&(mtx_fks[fk_r]));
	}
}

/**
 * @brief 	This function used to implement the mutex unlock for the forks.
 * 			Each thread (philosopher) must unlock the mutex of two forks
 * 			after eating with them.
 * 
 * @param t_var 
 */
void	ft_app_fork_mtx_unlock(t_threadvar *t_var)
{
	pthread_mutex_t	*mtx_fks;
	int				fk_r;
	int				fk_l;

	mtx_fks = t_var->a_var->mtx_forks;
	fk_r = (t_var->id) % (t_var->a_var->nbr_fork);
	fk_l = (t_var->id - 1) % (t_var->a_var->nbr_fork);
	if (t_var->id % 2 == 1)
	{
		pthread_mutex_unlock(&(mtx_fks[fk_l]));
		pthread_mutex_unlock(&(mtx_fks[fk_r]));
	}
	else
	{
		pthread_mutex_unlock(&(mtx_fks[fk_l]));
		pthread_mutex_unlock(&(mtx_fks[fk_r]));
	}
}

/**
 * @brief 	This function kicks in when only one philosopher is 
 * 			given by the user input. This ensure that the philosopher
 * 			starves to death, as each philosoper requires two forks
 * 			to eat its meal.
 * 
 * @param t_var 
 * @return int 
 */
int	ft_app_fork_lim_chk(t_threadvar *t_var)
{
	if (t_var->a_var->nbr_fork <= 1)
	{
		while (1)
		{
			ft_app_timestamp(t_var, &(t_var->clk_eat));
			if (t_var->ts_ms > (t_var->a_var->time_die))
			{
				ft_app_timestamp(t_var, &(t_var->clk_start));
				printf("%8ldms %2d died\n", t_var->ts_ms, t_var->id);
				t_var->a_var->rc_eat = ERR_PHILO_FORK_LIMIT;
				return (ERR_PHILO_FORK_LIMIT);
			}
		}
	}
	return (0);
}

/**
 * @brief 	This thread allocates memory for all philosopher threads creation,
 * 			variables for each thread and philosopher fork mutex. 
 * 
 * @param a 
 * @param t 
 * @param p 
 * @return int 
 */
int	ft_app_malloc_thr_mtx_var_ptrs(t_app *a, t_threadvar **t, pthread_t **p)
{
	*p = (pthread_t *)malloc(sizeof(pthread_t) * a->nbr_philo);
	*t = (t_threadvar *)malloc(sizeof(t_threadvar) * a->nbr_philo);
	a->mtx_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
												a->nbr_fork);
	if (p == NULL || t == NULL || a->mtx_forks == NULL)
	{
		printf("\nError\npthread malloc failed");
		return (-1);
	}
	return (0);
}

/**
 * @brief 	This function performs the intialisation protocol for the 
 * 			created threads (philosopher - pthread_t *).
 * 			variable for each thread (t_threadvar *),
 * 			mutexs for all the philosophers (pthread_mutex_t *) stored
 * 			in the application variable struct (t_app *).
 * 
 * @param a 
 * @param t 
 * @param p 
 */
void	ft_app_init_thr_mtx_var_ptrs(t_app *a, t_threadvar *t, pthread_t *p)
{
	int	idx;

	idx = 0;
	memset(p, 0, (sizeof(pthread_t) * a->nbr_philo));
	memset(t, 0, (sizeof(t_threadvar) * a->nbr_philo));
	while (idx < a->nbr_philo)
	{
		pthread_mutex_init(&(a->mtx_forks[idx]), NULL);
		idx++;
	}
}
