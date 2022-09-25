/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_malloc_thr_mtx_var_ptrs.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 16:05:39 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This thread allocates memory for all philosopher threads creation,
 * 			variables for each thread and philosopher fork mutex. 
 * 
 * @param a 
 * @param t 
 * @param p 
 * @return int 
 */
int	ft_app_malloc_thr_mtx_var_ptrs(t_app *a, t_threadvar **t, pthread_t **p)
{
	*p = (pthread_t *)malloc(sizeof(pthread_t) * a->nbr_philo);
	*t = (t_threadvar *)malloc(sizeof(t_threadvar) * a->nbr_philo);
	a->mtx_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
												a->nbr_fork);
	a->mtx_forks_state = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
												a->nbr_fork);
	a->forks_state = (int *)malloc(sizeof(int) * a->nbr_fork);
	if (p == NULL || t == NULL || a->mtx_forks == NULL)
	{
		printf("\nError\npthread malloc failed");
		return (-1);
	}
	return (0);
}
