/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_fork_lim_chk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/22 16:08:58 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

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
		pthread_mutex_lock(&(t_var->mtx_state));
		t_var->state = DEAD;
		pthread_mutex_unlock(&(t_var->mtx_state));
		usleep(t_var->time_die);
		return (ERR_PHILO_FORK_LIMIT);
	}
	return (0);
}
