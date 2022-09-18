/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:10:21 by cudoh            ###   ########.fr       */
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
 * @param args 
 * @return int 
 */
int	ft_app_eat(t_threadvar *args)
{
	ft_app_fork_mtx_lock(args);
	ft_app_timestamp(args, &(args->clk_start));
	pthread_mutex_lock(&(args->a_var->mtx_print));
	ft_app_stdout(" has taken a fork\n", 18, args);
	pthread_mutex_unlock(&(args->a_var->mtx_print));
	if (ft_app_is_philo_starved(args) == ERR_PHILO_STARVED)
		return (ERR_PHILO_STARVED);
	ft_app_timestamp(args, &(args->clk_start));
	pthread_mutex_lock(&(args->a_var->mtx_print));
	ft_app_stdout(" is eating\n", 11, args);
	pthread_mutex_unlock(&(args->a_var->mtx_print));
	if (ft_app_sleep_timer(args->time_eat) < 0)
		return (ERR_GET_TIME_OF_DAY);
	ft_app_fork_mtx_unlock(args);
	args->clk_eat.tv_sec = args->now.tv_sec;
	args->clk_eat.tv_usec = args->now.tv_usec;
	if (ft_app_count_eat(args) < 0)
		return (ERR_PHILO_EAT_LIMIT);
	return (0);
}
