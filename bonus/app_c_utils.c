/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_c_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/12 21:50:08 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_c_utils.h"

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
		while (1)
		{
			ft_app_timestamp(t_var, &(t_var->clk_eat));
			if (t_var->ts_ms > (t_var->a_var->time_die))
			{
				ft_app_timestamp(t_var, &(t_var->clk_start));
				sem_wait(t_var->a_var->sem_print);
				printf("%8ld %2d died\n", t_var->ts_ms, t_var->id);
				//sem_post(t_var->a_var->sem_print);
				t_var->a_var->rc_eat = ERR_PHILO_FORK_LIMIT;
				return (ERR_PHILO_FORK_LIMIT);
			}
		}
	}
	return (0);
}
