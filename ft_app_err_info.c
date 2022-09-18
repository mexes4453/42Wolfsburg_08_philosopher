/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_err_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:49:28 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function provides information of errors which occurred
 * 			during the threads execution after they exit.
 * 
 * @param a_var 
 */
void	ft_app_err_info(t_app *a_var)
{
	if (a_var->rc_eat == ERR_PHILO_EAT_LIMIT)
	{
		printf("\nSimulation Stopped!");
		printf("\nMinimum eat count reached for each thread\n");
	}
	else if (a_var->rc_eat == ERR_PHILO_STARVED)
		printf("\nSimulation stopped!\nA philosopher died of starvation\n");
	else if (a_var->rc_eat == ERR_PHILO_FORK_LIMIT)
	{
		printf("\nSimulation stopped!");
		printf("\nA philosopher must eat with two forks\n");
	}
}
