/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_var_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:10:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 *  This function initials all application variables from the user input
 * 
 */
int	ft_app_var_init(int argc, char *argv[], t_app *a)
{
	a->rc = 0;
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
	else
	{	
		a->nbr_eat = 0;
	}
	if (a->nbr_philo < 0 || a->time_die < 0 || a->time_eat < 0 || \
		a->time_slp < 0 || a->nbr_eat < 0)
		return (-1);
	a->cnt_thr_eat = 0;
	a->rc_eat = 0;
	pthread_mutex_init(&(a->mtx_rc), NULL);
	pthread_mutex_init(&(a->mtx_print), NULL);
	return (0);
}
