/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_chk_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/18 08:10:39 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

/**
 * 	This functions checks the validity of the user's input
 * 
 */
int	ft_app_chk_input(int argc)
{
	if (argc < 5)
	{
		printf("Error\nRequired args missing\n");
		return (-1);
	}
	else if (argc > 6)
	{
		printf("Error\nToo many arguments given");
		return (-1);
	}
	return (0);
}
