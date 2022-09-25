/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_var_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 17:02:51 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 *  This function initials all application variables from the user input
 * 
 */
int	ft_app_var_init(int argc, char *argv[], t_app *a)
{
	memset((void *)a, 0, sizeof(t_app));
	a->nbr_philo = ft_app_atoi(argv[1]);
	if (a->nbr_philo <= 0)
	{
		printf("\nError!\nPhilosophers must be more than zero\n");
		return (-1);
	}
	a->nbr_fork = a->nbr_philo;
	a->time_die = ft_app_atoi(argv[2]);
	a->time_eat = ft_app_atoi(argv[3]);
	a->time_slp = ft_app_atoi(argv[4]);
	if (argc > 5)
		a->nbr_eat = ft_app_atoi(argv[5]);
	if (a->nbr_philo < 0 || a->time_die < 0 || a->time_eat < 0 || \
		a->time_slp < 0 || a->nbr_eat < 0)
		return (-1);
	a->thrds_state = ft_queue_create(a->nbr_philo);
	pthread_mutex_init(&(a->mtx_rc), NULL);
	pthread_mutex_init(&(a->mtx_print), NULL);
	pthread_mutex_init(&(a->mtx_philo), NULL);
	pthread_mutex_init(&(a->thrds_state->mtx), NULL);
	return (0);
}
