/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_count_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 14:04:22 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

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
	if (t_var->nbr_eat > 0)
	{
		(t_var->cnt_eat)++;
		if (t_var->cnt_eat >= t_var->nbr_eat)
		{
			pthread_mutex_lock(&(t_var->a_var->mtx_rc));
			t_var->a_var->rc_eat = ERR_PHILO_EAT_LIMIT;
			pthread_mutex_unlock(&(t_var->a_var->mtx_rc));
			pthread_mutex_lock(&(t_var->mtx_state));
			t_var->state = FULL;
			pthread_mutex_unlock(&(t_var->mtx_state));
			pthread_mutex_lock(&(t_var->a_var->thrds_state->mtx));
			ft_queue_enqueue(t_var->a_var->thrds_state, t_var->id);
			pthread_mutex_unlock(&(t_var->a_var->thrds_state->mtx));
			return (ERR_PHILO_EAT_LIMIT);
		}
	}
	return (0);
}
