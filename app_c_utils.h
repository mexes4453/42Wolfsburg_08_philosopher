/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_c_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:05:26 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/10 22:17:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_C_UTILS_H
# define APP_C_UTILS_H
# include "philo_utils.h"

void	ft_app_fork_mtx_lock(t_threadvar *t_var);
void	ft_app_fork_mtx_unlock(t_threadvar *t_var);
int		ft_app_fork_lim_chk(t_threadvar *t_var);
int		ft_app_malloc_thr_mtx_var_ptrs(t_app *a, t_threadvar **t, \
													pthread_t **p);
void	ft_app_init_thr_mtx_var_ptrs(t_app *a, t_threadvar *t, pthread_t *p);
#endif