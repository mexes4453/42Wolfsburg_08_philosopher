/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_sleep_timer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 14:10:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function delays for a given period in ms
 * 
 * @param period 
 * @return int 
 */
int	ft_app_sleep_timer(int period)
{
	struct timeval	start;
	struct timeval	now;
	suseconds_t		td_ms;

	if (gettimeofday(&(start), NULL) < 0)
	{
		printf("\nError\ngettimeofday\n");
		return (-1);
	}
	while (1)
	{
		if (gettimeofday(&(now), NULL) < 0)
		{
			printf("\nError\ngettimeofday\n");
			return (-1);
		}
		td_ms = ft_app_clk_diff_ms(&now, &start);
		if (td_ms >= period)
			break ;
	}
	return (0);
}
