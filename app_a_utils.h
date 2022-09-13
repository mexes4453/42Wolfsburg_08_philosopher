/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_a_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:05:26 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/10 21:58:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_A_UTILS_H
# define APP_A_UTILS_H
# include "philo_utils.h"

int		ft_app_atoi(char *str_nbr);
int		ft_app_chk_input(int argc);
int		ft_app_var_init(int argc, char *argv[], t_app *a);
void	*ft_app_sleep(t_threadvar *args);
int		ft_app_eat(t_threadvar *args);
#endif
