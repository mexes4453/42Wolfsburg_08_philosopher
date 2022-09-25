/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 06:46:45 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function is executed by all philosopher thread.
 * 			It encompasses all the living activity of a philosopher
 * 			which includes, eat, sleep and think.
 * 
 * @param args 
 * @return void* 
 */
void	*ft_app_live(void *args)
{
	t_threadvar	*t_var;

	t_var = (t_threadvar *)args;
	gettimeofday(&(t_var->clk_start), NULL);
	t_var->clk_eat.tv_sec = t_var->clk_start.tv_sec;
	t_var->clk_eat.tv_usec = t_var->clk_start.tv_usec;
	while (1)
	{
		t_var->rc = ft_app_think(t_var);
		if (t_var->rc == ERR_PHILO_DIED)
			break ;
		t_var->rc = ft_app_eat(t_var);
		if (t_var->rc < 0)
			break ;
		t_var->rc = ft_app_sleep(t_var);
		if (t_var->rc < 0)
			break ;
	}
	return (args);
}
