/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:08:14 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/24 14:09:37 by cudoh            ###   ########.fr       */
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

static void	ft_app_stdout_all_nbr(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
		ft_app_stdout_nbr(nbr);
}

static int	ft_strlen(char *msg)
{
	int	idx;

	idx = 0;
	if (msg == NULL)
		return (0);
	while (msg[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

/**
 * @brief 	This function writes characters to screen using write function.
 * 
 * @param msg 
 * @param msglen 
 * @param t_var 
 */
void	ft_app_stdout(char *msg, pthread_mutex_t *mtx, \
						suseconds_t ts, int tid)
{
	int	msglen;

	msglen = ft_strlen(msg);
	pthread_mutex_lock(mtx);
	ft_app_stdout_all_nbr(ts);
	write(1, " ", 1);
	ft_app_stdout_nbr(tid);
	write(1, msg, msglen);
	pthread_mutex_unlock(mtx);
}

void	ft_app_stdmsg(char *msg, pthread_mutex_t *mtx)
{
	int	msglen;

	msglen = ft_strlen(msg);
	pthread_mutex_lock(mtx);
	write(1, msg, msglen);
	pthread_mutex_unlock(mtx);
}
