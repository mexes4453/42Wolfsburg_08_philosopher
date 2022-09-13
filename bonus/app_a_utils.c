/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_a_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:33:38 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/12 22:07:14 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_a_utils.h"

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

/**
 *  This function initials all application variables from the user input
 * 
 */
int	ft_app_var_init(int argc, char *argv[], t_app *a)
{
	a->rc = 0;
	a->nbr_philo = ft_app_atoi(argv[1]);
	if (a->nbr_philo <= 0)
	{
		printf("\nError!\nPhilosophers must be more than zero\n");
		return (-1);
	}
	a->nbr_fork = a->nbr_philo;
	a->time_die = ft_app_atoi(argv[2]);
	a->time_eat = ft_app_atoi(argv[3]);
	a->time_slp = ft_app_atoi(argv[4]);
	if (argc > 5)
		a->nbr_eat = ft_app_atoi(argv[5]);
	else
	{	
		a->nbr_eat = 0;
	}
	if (a->nbr_philo < 0 || a->time_die < 0 || a->time_eat < 0 || \
		a->time_slp < 0 || a->nbr_eat < 0)
		return (-1);
	a->cnt_thr_eat = 0;
	a->rc_eat = 0;
	return (0);
}

void	*ft_app_sleep(t_threadvar *args)
{
	ft_app_timestamp(args, &(args->clk_start));
	sem_wait(args->a_var->sem_print);
	printf("%8ld %2d is sleeping\n", args->ts_ms, args->id);
	sem_post(args->a_var->sem_print);
	usleep(args->a_var->time_slp * MSEC);
	return (args);
}

/**
 * @brief 	This function defines how the philosopher should eat.
 * 			it must acquire the fork mutex before it can eat and 
 * 			if successful, it must unlock the mutex after eating
 * 			and should update the eat time for next time diff calculation.
 * 			This is how a starving philosopher can be detected.
 * 			It also tracks the time elapsed since last meal to indicate
 * 			if the philopher has starved to death.
 * 
 * @param args 
 * @return int 
 */
int	ft_app_eat(t_threadvar *args)
{
	sem_wait(args->a_var->sem_forks);
	sem_wait(args->a_var->sem_forks);
	ft_app_timestamp(args, &(args->clk_start));
	sem_wait(args->a_var->sem_print);
	printf("%8ld %2d has taken a fork\n", args->ts_ms, args->id);
	sem_post(args->a_var->sem_print);
	if (ft_app_is_philo_starved(args) == ERR_PHILO_STARVED)
		return (ERR_PHILO_STARVED);
	ft_app_timestamp(args, &(args->clk_start));
	usleep(args->a_var->time_eat * MSEC);
	sem_post(args->a_var->sem_forks);
	sem_post(args->a_var->sem_forks);
	sem_wait(args->a_var->sem_print);
	printf("%8ld %2d is eating\n", args->ts_ms, args->id);
	sem_post(args->a_var->sem_print);
	args->clk_eat.tv_sec = args->now.tv_sec;
	args->clk_eat.tv_usec = args->now.tv_usec;
	if (ft_app_count_eat(args) < 0)
		return (ERR_PHILO_EAT_LIMIT);
	return (0);
}
