/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_fork_mtx_unlock.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 19:21:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 		This function performs the fork unlock in a predefined
 * 				manner (right fork first - default for philo thread with odd
 * 						id number)
 * 
 * @param t_var 
 * @param fk_l 
 * @param fk_r 
 */
static void	ft_fk_unlock(t_threadvar *t_var, int fk_l, int fk_r)
{
	pthread_mutex_t	*mtx_fks;

	mtx_fks = t_var->a_var->mtx_forks;
	if (t_var->locked_forks >= 1)
	{
		pthread_mutex_unlock(&(mtx_fks[fk_r]));
		pthread_mutex_lock(&(t_var->a_var->mtx_forks_state[fk_r]));
		t_var->a_var->forks_state[fk_r] = FORK_FREE;
		pthread_mutex_unlock(&(t_var->a_var->mtx_forks_state[fk_r]));
		t_var->locked_forks--;
	}
	if (t_var->locked_forks == 1)
	{
		pthread_mutex_unlock(&(mtx_fks[fk_l]));
		pthread_mutex_lock(&(t_var->a_var->mtx_forks_state[fk_l]));
		t_var->a_var->forks_state[fk_l] = FORK_FREE;
		pthread_mutex_unlock(&(t_var->a_var->mtx_forks_state[fk_l]));
		t_var->locked_forks--;
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
	int	fk_r;
	int	fk_l;

	fk_r = (t_var->id) % (t_var->a_var->nbr_fork);
	fk_l = (t_var->id - 1) % (t_var->a_var->nbr_fork);
	if (t_var->id % 2 == 1)
	{
		ft_fk_unlock(t_var, fk_l, fk_r);
	}
	else
	{
		ft_fk_unlock(t_var, fk_r, fk_l);
	}
}
