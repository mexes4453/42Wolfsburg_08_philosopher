/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:36:59 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 07:41:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	main(int argc, char *argv[])
{
	t_app		a_var;
	pthread_t	*philo_threads;
	t_threadvar	*thread_vars;

	if (ft_app_chk_input(argc) < 0)
		return (-1);
	if (ft_app_var_init(argc, argv, &a_var) < 0)
		return (-1);
	if (ft_app_malloc_thr_mtx_var_ptrs(&a_var, &thread_vars, \
												&philo_threads) < 0)
		return (-1);
	ft_app_init_thr_mtx_var_ptrs(&a_var, thread_vars, philo_threads);
	if (ft_app_create_thrds(&a_var, thread_vars, philo_threads) < 0)
		return (-1);
	if (ft_app_threads_rejoin(&a_var, philo_threads) < 0)
		return (-1);
	ft_app_err_info(&a_var);
	ft_app_free_mem(philo_threads, &a_var, thread_vars);
	return (0);
}
