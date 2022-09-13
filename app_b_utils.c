/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_b_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/10 22:26:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_b_utils.h"

void	*ft_app_think(t_threadvar *args)
{
	ft_app_timestamp(args, &(args->clk_start));
	printf("%8ld %2d is thinking\n", args->ts_ms, args->id);
	return (args);
}

/**
 * @brief 	This function is executed by all philosopher thread.
 * 			It encompasses all the living activity of a philosopher
 * 			which includes, eat, sleep and think.
 * 
 * @param args 
 * @return void* 
 */
void	*ft_app_live(void *args)
{
	t_threadvar	*t_var;

	t_var = (t_threadvar *)args;
	gettimeofday(&(t_var->clk_start), NULL);
	t_var->clk_eat.tv_sec = t_var->clk_start.tv_sec;
	t_var->clk_eat.tv_usec = t_var->clk_start.tv_usec;
	while (1)
	{
		if (ft_app_fork_lim_chk(t_var) == ERR_PHILO_FORK_LIMIT)
			break ;
		if (ft_app_eat(t_var) == ERR_PHILO_EAT_LIMIT)
		{
			t_var->a_var->rc_eat = ERR_PHILO_EAT_LIMIT;
			break ;
		}
		else if (t_var->a_var->rc_eat == ERR_PHILO_STARVED)
			break ;
		ft_app_sleep(t_var);
		ft_app_think(t_var);
	}
	return (args);
}

/**
 * @brief 	Computes the time difference between the current time (now) and a
 * 			reference time (clk).
 * 			The time difference are computed in milliseconds.
 * todo		Rely on the timestamp value saved in ts_ms (t_threadvar) after use
 * @param t_var 
 * @param clk 
 * @return int 
 */
int	ft_app_timestamp(t_threadvar *t_var, struct timeval *clk)
{
	if (gettimeofday(&(t_var->now), NULL) < 0)
	{
		printf("\nError\ngettimeofday\n");
		return (-1);
	}
	t_var->time_diff.tv_sec = t_var->now.tv_sec - clk->tv_sec;
	if (t_var->now.tv_usec > clk->tv_usec)
		t_var->time_diff.tv_usec = t_var->now.tv_usec - clk->tv_usec;
	else
	{
		(t_var->time_diff.tv_sec)--;
		t_var->time_diff.tv_usec = (t_var->now.tv_usec + USEC) - clk->tv_usec;
	}
	t_var->ts_ms = (t_var->time_diff.tv_sec * MSEC) + \
					(t_var->time_diff.tv_usec / MSEC);
	return (0);
}

/**
 * @brief 	This function tracks how many time a philosopher has 
 * 			eaten only when the number of time they must is given
 * 			by the user input.
 * 			The function triggers a thread exit once the given number
 * 			of eat per philosopher has been attained by each thread.
 * 
 * @param t_var 
 * @return int 
 */
int	ft_app_count_eat(t_threadvar *t_var)
{
	if (t_var->a_var->nbr_eat > 0)
	{
		(t_var->cnt_eat)++;
		if (t_var->cnt_eat == t_var->a_var->nbr_eat)
			return (-1);
	}
	return (0);
}

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
	ft_app_timestamp(t_var, &(t_var->clk_eat));
	if (t_var->ts_ms > (t_var->a_var->time_die))
	{
		ft_app_timestamp(t_var, &(t_var->clk_start));
		printf("%8ldms %2d died\n", t_var->ts_ms, t_var->id);
		t_var->a_var->rc_eat = ERR_PHILO_STARVED;
		ft_app_fork_mtx_unlock(t_var);
		return (ERR_PHILO_STARVED);
	}
	else if (t_var->a_var->rc_eat == ERR_PHILO_STARVED)
	{
		ft_app_fork_mtx_unlock(t_var);
		return (ERR_PHILO_STARVED);
	}
	return (0);
}
