/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_fork_mtx_lock.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 08:34:26 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function performs the mutex lock and unlock for the philo
 * 			forks at the same time checking if the philo starves before
 * 			acquiring the forks.
 * 			This is done by using the philo id as idx number for fetch the
 * 			corresponding fork state and locking their mutexes.
 * @param	t_var
 * @param	fk_idx
 * @param	mtx_fks
 */
static int	ft_lock_fork(t_threadvar *t_var, int fk_idx, \
						pthread_mutex_t *mtx_fks)
{
	t_app	*a_var;

	a_var = t_var->a_var;
	while (1)
	{
		t_var->rc = ft_atm_rw(&(a_var->mtx_forks_state[fk_idx]), \
										0, 0, &(a_var->forks_state[fk_idx]));
		if (t_var->rc == FORK_FREE)
		{
			pthread_mutex_lock(&(mtx_fks[fk_idx]));
			ft_atm_rw(&(a_var->mtx_forks_state[fk_idx]), \
								1, FORK_TAKEN, &a_var->forks_state[fk_idx]);
			t_var->locked_forks++;
			break ;
		}
		gettimeofday(&(t_var->now), NULL);
		if (ft_app_is_philo_starved(t_var) < 0)
			return (ERR_PHILO_STARVED);
	}
	return (0);
}

/**
 * @brief 	This function used to implement the mutex lock for the forks.
 * 			Each thread (philosopher) must lock the mutex of two forks.
 * 			They must secure the forks adjacent to them.
 *
 * @param t_var
 */
int	ft_app_fork_mtx_lock(t_threadvar *t_var)
{
	pthread_mutex_t	*mtx_fks;
	int				fk_r;
	int				fk_l;

	mtx_fks = t_var->a_var->mtx_forks;
	fk_r = (t_var->id) % (t_var->a_var->nbr_fork);
	fk_l = (t_var->id - 1) % (t_var->a_var->nbr_fork);
	if (t_var->id % 2 == 1)
	{
		if (ft_lock_fork(t_var, fk_r, mtx_fks) < 0)
			return (ERR_PHILO_STARVED);
		if (ft_lock_fork(t_var, fk_l, mtx_fks) < 0)
			return (ERR_PHILO_STARVED);
	}
	else
	{
		if (ft_lock_fork(t_var, fk_l, mtx_fks) < 0)
			return (ERR_PHILO_STARVED);
		if (ft_lock_fork(t_var, fk_r, mtx_fks) < 0)
			return (ERR_PHILO_STARVED);
	}
	return (0);
}
