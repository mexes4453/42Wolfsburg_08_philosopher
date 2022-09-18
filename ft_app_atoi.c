/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:10:28 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * 	This function converts string of numbers to single integer number
 * 
 */
int	ft_app_atoi(char *str_nbr)
{
	int	idx;
	int	int_nbr;

	idx = 0;
	int_nbr = 0;
	while (str_nbr[idx] != '\0')
	{
		if (str_nbr[idx] >= '0' && str_nbr[idx] <= '9')
		{
			int_nbr *= 10;
			int_nbr += (str_nbr[idx] - 0x30);
		}
		else
		{
			printf("\nError!\nAll input value must be positive integer\n");
			return (-1);
		}
		idx++;
	}
	return (int_nbr);
}
