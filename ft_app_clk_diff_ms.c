/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_clk_diff_ms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:55:58 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	this function computes the time difference in ms 
 * 			between two time stuct val.
 * 
 * @param n 
 * @param s 
 * @return suseconds_t 
 */
suseconds_t	ft_app_clk_diff_ms(struct timeval *n, struct timeval *s)
{
	suseconds_t		td_ms;
	struct timeval	time_diff;

	td_ms = 0;
	time_diff.tv_sec = n->tv_sec - s->tv_sec;
	if (n->tv_usec > s->tv_usec)
		time_diff.tv_usec = n->tv_usec - s->tv_usec;
	else
	{
		(time_diff.tv_sec)--;
		time_diff.tv_usec = (n->tv_usec + USEC) - s->tv_usec;
	}
	td_ms = (time_diff.tv_sec * MSEC) + (time_diff.tv_usec / MSEC);
	return (td_ms);
}
