/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/11 21:09:00 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_d_utils.h"

/**
 * @brief 	This function creates the threads for all philosphers.
 * 			It also initialise the thread variables. (t_threadvar)
 * 
 * @param a_var 
 * @param t_vars 
 * @param p_thrds 
 * @return int 
 */
/*
int	ft_app_create_thrds(t_app *a_var, t_threadvar *t_vars, pthread_t *p_thrds)
{
	int	idx;

	idx = 0;
	a_var->rc = 0;
	while (idx < a_var->nbr_philo)
	{
		t_vars[idx].id = idx + 1;
		t_vars[idx].a_var = a_var;
		a_var->rc = pthread_create(&(p_thrds[idx]), NULL, \
										ft_app_live, (void *)(&t_vars[idx]));
		if (a_var->rc != 0)
		{
			printf("\nError\npthread creation failed");
			return (-1);
		}
		idx++;
	}	
	return (0);
}
*/
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
		pthread_mutex_destroy(&(a_var->mtx_forks[idx]));
		idx++;
	}
	return (0);
}

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

/**
 * @brief This function handles the release of all memory for the program
 * 
 * @param t 
 * @param m 
 * @param v 
 */
void	ft_app_free_mem(pthread_t *t, pthread_mutex_t *m, t_threadvar *v)
{
	free(m);
	free(t);
	free(v);
}
