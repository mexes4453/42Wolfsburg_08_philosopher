/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 09:00:05 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	ft_app_think(t_threadvar *t_var)
{
	t_state	state;

	state = (t_state)ft_atm_rw(&t_var->mtx_state, 0, 0, (int *)&t_var->state);
	if (ft_app_is_philo_dead(t_var) < 0 || state == DEAD)
		return (ERR_PHILO_DIED);
	if (state == THINK)
	{
		t_var->ts_ms = ft_app_timestamp(t_var, &(t_var->clk_start));
		ft_app_stdout(" is thinking\n", &(t_var->a_var->mtx_print), \
						t_var->ts_ms, t_var->id);
		if (ft_app_fork_mtx_lock(t_var) < 0)
		{
			return (ERR_PHILO_STARVED);
		}
	}
	if (ft_app_is_philo_dead(t_var) < 0 || state == DEAD)
		return (ERR_PHILO_DIED);
	t_var->ts_ms = ft_app_timestamp(t_var, &(t_var->clk_start));
	ft_app_stdout(" has taken a fork\n", &(t_var->a_var->mtx_print), \
					t_var->ts_ms, t_var->id);
	ft_atm_rw(&t_var->mtx_state, 1, EAT, (int *)&t_var->state);
	return (0);
}
