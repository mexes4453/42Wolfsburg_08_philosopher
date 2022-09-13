/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_b_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:05:26 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/11 20:09:01 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_B_UTILS_H
# define APP_B_UTILS_H
# include "philo_utils.h"

void	*ft_app_think(t_threadvar *args);
int 	ft_app_live(t_threadvar	*t_var);
int		ft_app_timestamp(t_threadvar *t_var, struct timeval *clk);
int		ft_app_count_eat(t_threadvar *t_var);
int		ft_app_is_philo_starved(t_threadvar *t_var);
#endif
