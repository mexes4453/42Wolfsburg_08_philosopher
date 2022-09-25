/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_is_philo_starved.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:35:34 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 14:13:09 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function check if the philosopher has starved to death
 * 			after acquiring the fork mutex. Once detected it must relinquish
 * 			the fork mutex immediately.
 * 			It also enables other threads (philosopher) to detect that one
 * 			of the philosopher (thread) has died of starvation and would
 * 			enable the trigger of their exit. (halting the complete simulation)
 * 
 * @param t_var 
 * @return int 
 */
int	ft_app_is_philo_starved(t_threadvar *t_var)
{
	t_var->ts_ms = ft_app_timestamp(t_var, &(t_var->clk_eat));
	if (t_var->ts_ms > (t_var->time_die))
	{
		pthread_mutex_lock(&(t_var->mtx_state));
		t_var->state = DEAD;
		pthread_mutex_unlock(&(t_var->mtx_state));
		pthread_mutex_lock(&(t_var->a_var->thrds_state->mtx));
		ft_queue_enqueue(t_var->a_var->thrds_state, t_var->id);
		pthread_mutex_unlock(&(t_var->a_var->thrds_state->mtx));
		ft_app_fork_mtx_unlock(t_var);
		return (ERR_PHILO_STARVED);
	}
	return (0);
}

int	ft_app_is_philo_dead(t_threadvar *t_var)
{
	pthread_mutex_lock(&(t_var->mtx_state));
	t_var->rc = t_var->state;
	pthread_mutex_unlock(&(t_var->mtx_state));
	if (t_var->rc == DEAD)
	{
		ft_app_fork_mtx_unlock(t_var);
		return (ERR_PHILO_DIED);
	}
	return (0);
}
