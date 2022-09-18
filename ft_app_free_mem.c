/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_free_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:50:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 09:44:57 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function handles the release of all memory and resources 
 * 			allocated for the program.
 * 
 * @param t 
 * @param m 
 * @param v 
 */
void	ft_app_free_mem(pthread_t *t, t_app *a_var, t_threadvar *v)
{
	int	idx;

	idx = 0;
	while (idx < a_var->nbr_philo)
	{
		pthread_mutex_destroy(&(a_var->mtx_forks[idx]));
		idx++;
	}
	pthread_mutex_destroy(&(a_var->mtx_rc));
	pthread_mutex_destroy(&(a_var->mtx_print));
	free(a_var->mtx_forks);
	free(t);
	free(v);
}
