/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_threads_rejoin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 13:36:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function waits for all created thread to rejoin
 * 			the main thread (pthread_join).
 * 			It also destroy all mutex pointer created for each thread.
 * 
 * @param a_var 
 * @param philo_threads 
 * @return int 
 */
int	ft_app_threads_rejoin(t_app *a_var, pthread_t *philo_threads)
{
	int	idx;

	idx = 0;
	a_var->rc = 0;
	while (idx < a_var->nbr_philo)
	{
		a_var->rc = pthread_join(philo_threads[idx], NULL);
		if (a_var->rc != 0)
		{
			printf("\nError\npthread join failed\n");
			return (-1);
		}
		idx++;
	}
	return (0);
}
