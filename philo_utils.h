/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:03:10 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/25 09:02:33 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include "queue_utils.h"
# include "datatype_const.h"

int			ft_app_atoi(char *str_nbr);
int			ft_app_chk_input(int argc);
int			ft_app_var_init(int argc, char *argv[], t_app *a);
int			ft_app_sleep(t_threadvar *args);
int			ft_app_eat(t_threadvar *args);
int			ft_app_think(t_threadvar *args);
void		*ft_app_live(void *args);
suseconds_t	ft_app_timestamp(t_threadvar *t_var, struct timeval *clk);
int			ft_app_count_eat(t_threadvar *t_var);
int			ft_app_is_philo_starved(t_threadvar *t_var);
int			ft_atm_rw(pthread_mutex_t *mtx, int flag, \
							int val, int *arg);
int			ft_app_fork_mtx_lock(t_threadvar *t_var);
void		ft_app_fork_mtx_unlock(t_threadvar *t_var);
int			ft_app_fork_lim_chk(t_threadvar *t_var);
int			ft_app_malloc_thr_mtx_var_ptrs(t_app *a, t_threadvar **t, \
													pthread_t **p);
void		ft_app_init_thr_mtx_var_ptrs(t_app *a, t_threadvar *t, \
													pthread_t *p);
int			ft_app_create_thrds(t_app *a_var, \
							t_threadvar *t_vars, pthread_t *p_thrds);
int			ft_app_threads_rejoin(t_app *a_var, pthread_t *philo_threads);
void		ft_app_free_mem(pthread_t *t, t_app *a_var, t_threadvar *v);
int			ft_app_sleep_timer(int period);
suseconds_t	ft_app_clk_diff_ms(struct timeval *n, struct timeval *s);
void		ft_app_stdout(char *msg, pthread_mutex_t *mtx, \
						suseconds_t ts, int tid);
int			ft_app_detect_death(t_threadvar *t_vars, t_app *a_var);
int			ft_app_is_philo_dead(t_threadvar *t_var);
void		ft_app_stdmsg(char *msg, pthread_mutex_t *mtx);

#endif
