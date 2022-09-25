/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_init_thr_mtx_var_ptrs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:38:46 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 09:10:44 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function performs the intialisation protocol for the 
 * 			created threads (philosopher - pthread_t *).
 * 			variable for each thread (t_threadvar *),
 * 			mutexs for all the philosophers (pthread_mutex_t *) stored
 * 			in the application variable struct (t_app *).
 * 
 * @param a 
 * @param t 
 * @param p 
 */
void	ft_app_init_thr_mtx_var_ptrs(t_app *a, t_threadvar *t, pthread_t *p)
{
	int	idx;

	idx = 0;
	memset(p, 0, (sizeof(pthread_t) * a->nbr_philo));
	memset(t, 0, (sizeof(t_threadvar) * a->nbr_philo));
	memset(a->forks_state, 1, (sizeof(int) * a->nbr_philo));
	while (idx < a->nbr_philo)
	{
		pthread_mutex_init(&(a->mtx_forks[idx]), NULL);
		pthread_mutex_init(&(a->mtx_forks_state[idx]), NULL);
		idx++;
	}
}
