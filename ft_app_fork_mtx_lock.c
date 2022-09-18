/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_fork_mtx_lock.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:30:35 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

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
		pthread_mutex_lock(&(mtx_fks[fk_r]));
		pthread_mutex_lock(&(mtx_fks[fk_l]));
	}
	else
	{
		pthread_mutex_lock(&(mtx_fks[fk_l]));
		pthread_mutex_lock(&(mtx_fks[fk_r]));
	}
}
