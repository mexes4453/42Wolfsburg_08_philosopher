/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 14:07:12 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	Computes the time difference between the current time (now) and a
 * 			reference time (clk).
 * 			The time difference are computed in milliseconds.
 * todo		Rely on the timestamp value saved in ts_ms (t_threadvar) after use
 * @param t_var 
 * @param clk 
 * @return int 
 */
suseconds_t	ft_app_timestamp(t_threadvar *t_var, struct timeval *clk)
{
	suseconds_t	ts_ms;

	if (gettimeofday(&(t_var->now), NULL) < 0)
	{
		printf("\nError\ngettimeofday\n");
		return (-1);
	}
	ts_ms = ft_app_clk_diff_ms(&t_var->now, clk);
	return (ts_ms);
}
