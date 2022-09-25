/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_detect_death.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:03:51 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 06:41:50 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

static void	ft_thrd_state_que_dequeue(int *thr_id, t_app *a_var)
{
	int	rc;

	rc = -1;
	while (1)
	{
		pthread_mutex_lock(&(a_var->thrds_state->mtx));
		rc = ft_queue_pop(a_var->thrds_state, thr_id);
		pthread_mutex_unlock(&(a_var->thrds_state->mtx));
		if (rc < 0)
		{
			usleep(SCAN_DELAY);
			continue ;
		}
		else
			break ;
	}
}

static void	ft_kill_all_thrd(t_app *a_var, t_threadvar *t_vars, int idx)
{
	a_var->ts_ms = ft_app_timestamp(&t_vars[idx], &(t_vars[idx].clk_start));
	ft_app_stdout(" died\n", &(a_var->mtx_print), a_var->ts_ms, idx + 1);
	idx = 0;
	while (idx < a_var->nbr_philo)
	{
		pthread_mutex_lock(&(t_vars[idx].mtx_state));
		t_vars[idx].state = DEAD;
		pthread_mutex_unlock(&(t_vars[idx].mtx_state));
		idx++;
	}
}

int	ft_app_detect_death(t_threadvar *t_vars, t_app *a_var)
{
	int		idx;
	t_state	state;

	idx = 0;
	while (1)
	{
		ft_thrd_state_que_dequeue(&idx, a_var);
		idx--;
		pthread_mutex_lock(&(t_vars[idx].mtx_state));
		state = t_vars[idx].state;
		pthread_mutex_unlock(&(t_vars[idx].mtx_state));
		if (state == DEAD)
		{
			ft_kill_all_thrd(a_var, t_vars, idx);
			return (ERR_PHILO_STARVED);
		}
		else if (state == FULL)
			return (ERR_PHILO_EAT_LIMIT);
		else
			return (0);
	}
	return (0);
}
