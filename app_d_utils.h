/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_d_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:18:02 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/10 22:18:08 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_D_UTILS_H
# define APP_D_UTILS_H
# include "philo_utils.h"

int		ft_app_create_thrds(t_app *a_var, \
							t_threadvar *t_vars, pthread_t *p_thrds);
int		ft_app_threads_rejoin(t_app *a_var, pthread_t *philo_threads);
void	ft_app_err_info(t_app *a_var);
void	ft_app_free_mem(pthread_t *t, pthread_mutex_t *m, t_threadvar *v);
#endif
