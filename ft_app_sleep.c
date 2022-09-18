/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:10:48 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

void	*ft_app_sleep(t_threadvar *args)
{
	ft_app_timestamp(args, &(args->clk_start));
	pthread_mutex_lock(&(args->a_var->mtx_print));
	ft_app_stdout(" is sleeping\n", 13, args);
	pthread_mutex_unlock(&(args->a_var->mtx_print));
	ft_app_sleep_timer(args->time_slp);
	return (args);
}
