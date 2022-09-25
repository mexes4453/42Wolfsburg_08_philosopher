/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atm_rw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:43:31 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 07:43:34 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	ft_atm_rw(pthread_mutex_t *mtx, int flag, int val, int *arg)
{
	int	rc;

	rc = 0;
	if (flag == 1)
	{
		pthread_mutex_lock(mtx);
		*arg = val;
		pthread_mutex_unlock(mtx);
	}
	else
	{
		pthread_mutex_lock(mtx);
		rc = *arg;
		pthread_mutex_unlock(mtx);
		return (rc);
	}
	return (0);
}
