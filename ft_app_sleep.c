/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 08:41:33 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This functions checks if a philo thread dies of starvation while
 * 			sleeping. it notifies the main thread by adding its thread id
 * 			to the queue system of dead threads for the main thread to make
 * 			the annoucement.
 * 
 * @param t_var 
 * @return int 
 */
static int	ft_sleep_is_dead(t_threadvar *t_var)
{
	gettimeofday(&(t_var->now), NULL);
	t_var->ts_ms = ft_app_clk_diff_ms(&(t_var->now), &(t_var->clk_eat));
	if (t_var->ts_ms > t_var->time_die)
	{
		ft_atm_rw(&t_var->mtx_state, 1, DEAD, (int *)&t_var->state);
		pthread_mutex_lock(&(t_var->a_var->thrds_state->mtx));
		ft_queue_enqueue(t_var->a_var->thrds_state, t_var->id);
		pthread_mutex_unlock(&(t_var->a_var->thrds_state->mtx));
		return (ERR_PHILO_STARVED);
	}
	return (0);
}

int	ft_app_sleep(t_threadvar *t_var)
{
	t_state			state;
	struct timeval	clk_slp;

	state = (t_state)ft_atm_rw(&t_var->mtx_state, 0, 0, (int *)&t_var->state);
	gettimeofday(&(clk_slp), NULL);
	if (ft_app_is_philo_dead(t_var) < 0 || state == DEAD)
		return (ERR_PHILO_DIED);
	t_var->ts_ms = ft_app_timestamp(t_var, &(t_var->clk_start));
	ft_app_stdout(" is sleeping\n", &(t_var->a_var->mtx_print), \
					t_var->ts_ms, t_var->id);
	while (1)
	{
		if (ft_sleep_is_dead(t_var) < 0)
			return (ERR_PHILO_STARVED);
		t_var->ts_ms = ft_app_clk_diff_ms(&(t_var->now), &clk_slp);
		if (t_var->ts_ms >= (t_var->time_slp))
			break ;
	}
	state = (t_state)ft_atm_rw(&t_var->mtx_state, 0, 0, (int *)&t_var->state);
	if (ft_app_is_philo_dead(t_var) < 0 || state == DEAD)
		return (ERR_PHILO_DIED);
	ft_atm_rw(&t_var->mtx_state, 1, THINK, (int *)&t_var->state);
	return (0);
}
