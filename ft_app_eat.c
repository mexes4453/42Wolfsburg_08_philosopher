/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 08:35:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function defines how the philosopher should eat.
 * 			it must acquire the fork mutex before it can eat and 
 * 			if successful, it must unlock the mutex after eating
 * 			and should update the eat time for next time diff calculation.
 * 			This is how a starving philosopher can be detected.
 * 			It also tracks the time elapsed since last meal to indicate
 * 			if the philopher has starved to death.
 * 
 * @param t_var 
 * @return int 
 */
int	ft_app_eat(t_threadvar *t_var)
{
	t_state	state;

	pthread_mutex_lock(&(t_var->mtx_state));
	state = t_var->state;
	pthread_mutex_unlock(&(t_var->mtx_state));
	if (ft_app_is_philo_starved(t_var) < 0 || state == DEAD)
		return (ERR_PHILO_STARVED);
	if (state == EAT)
	{
		t_var->ts_ms = ft_app_timestamp(t_var, &(t_var->clk_start));
		ft_app_stdout(" is eating\n", &(t_var->a_var->mtx_print), \
										t_var->ts_ms, t_var->id);
		t_var->clk_eat.tv_sec = t_var->now.tv_sec;
		t_var->clk_eat.tv_usec = t_var->now.tv_usec;
		if (ft_app_sleep_timer(t_var->time_eat) < 0)
			return (ERR_GET_TIME_OF_DAY);
	}
	ft_app_fork_mtx_unlock(t_var);
	if (ft_app_is_philo_dead(t_var) < 0)
		return (ERR_PHILO_DIED);
	if (ft_app_count_eat(t_var) < 0)
		return (ERR_PHILO_EAT_LIMIT);
	ft_atm_rw(&t_var->mtx_state, 1, SLEEP, (int *)&t_var->state);
	return (0);
}
