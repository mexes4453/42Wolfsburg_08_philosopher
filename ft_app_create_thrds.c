/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_create_thrds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:43:04 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function creates the threads for all philosphers.
 * 			It also initialise the thread variables. (t_threadvar)
 * 
 * @param a_var 
 * @param t_vars 
 * @param p_thrds 
 * @return int 
 */
int	ft_app_create_thrds(t_app *a_var, t_threadvar *t_vars, pthread_t *p_thrds)
{
	int	idx;

	idx = 0;
	a_var->rc = 0;
	while (idx < a_var->nbr_philo)
	{
		t_vars[idx].id = idx + 1;
		t_vars[idx].a_var = a_var;
		t_vars[idx].time_die = a_var->time_die;
		t_vars[idx].time_eat = a_var->time_eat;
		t_vars[idx].time_slp = a_var->time_slp;
		t_vars[idx].nbr_eat = a_var->nbr_eat;
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
