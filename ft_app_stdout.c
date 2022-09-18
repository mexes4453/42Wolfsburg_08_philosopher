/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:38:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:57:23 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * @brief 	This function prints numbers on screen using the write function.
 * 			each digit within the number is recursively converted to char and
 * 			written to the stdout.
 * 
 * @param nbr 
 */
static	void	ft_app_stdout_nbr(int nbr)
{
	char	rem;

	rem = 0;
	if (nbr)
	{
		rem = (nbr % 10) + 0x30;
		nbr = nbr / 10;
		ft_app_stdout_nbr(nbr);
		write(1, &rem, 1);
	}
}

/**
 * @brief 	This function writes characters to screen using write function.
 * 
 * @param msg 
 * @param msglen 
 * @param t_var 
 */
void	ft_app_stdout(char *msg, int msglen, t_threadvar *t_var)
{
	ft_app_stdout_nbr(t_var->ts_ms);
	write(1, " ", 1);
	ft_app_stdout_nbr(t_var->id);
	write(1, msg, msglen);
}
