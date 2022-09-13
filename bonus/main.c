/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:36:59 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/12 21:43:03 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	main(int argc, char *argv[])
{
	t_app		a_var;
	t_threadvar	*p_var;
	int	idx_proc;
	int pid;

	idx_proc = 1;
	if (ft_app_chk_input(argc) < 0)
		return (-1);
	if (ft_app_var_init(argc, argv, &a_var) < 0)
		return (-1);
	sem_unlink(PATH_SEM);
	sem_unlink(PATH_SEM_PRINT);
	a_var.sem_forks = sem_open(PATH_SEM, (O_CREAT), (S_IRUSR | S_IWUSR), \
									(unsigned int)a_var.nbr_fork);
	a_var.sem_print = sem_open(PATH_SEM_PRINT, (O_CREAT), \
								(S_IRUSR | S_IWUSR), SEM_PRINT_INIT);
									
	if (a_var.sem_forks == SEM_FAILED)
	{
		printf("\nError: sem_open failed!\n");
		return (-1);
	}
	
	while (idx_proc <= a_var.nbr_philo)
	{
		pid = fork();
		if (pid < 0)
		{
			printf("\nError: fork failed\n");
			return (-1);
		}
		else if (pid == 0)		// child process
		{
			p_var = (t_threadvar *)malloc(sizeof(t_threadvar));
			memset(p_var, 0, (sizeof(t_threadvar)));
			p_var->id = idx_proc;
			p_var->a_var = &a_var;
			break ;
		}
		idx_proc++;
	}
	
	if (pid == 0)
	{
		a_var.rc = ft_app_live(p_var);
		if (a_var.rc == ERR_PHILO_STARVED)
		{
			printf("\nSimulation stopped!\nOne Philosopher died\n");
			free(p_var);
			sem_close(a_var.sem_forks);
			sem_unlink(PATH_SEM);
			sem_close(a_var.sem_print);
			sem_unlink(PATH_SEM_PRINT);
			kill(0, SIGTERM);
		}
		free(p_var);
	}
	// main process execution here
	while (wait(NULL) != -1)
	{
		printf("\nProcess joined\n");
	}
	//  clean up
	sem_close(a_var.sem_forks);
	sem_unlink(PATH_SEM);
	sem_close(a_var.sem_print);
	sem_unlink(PATH_SEM_PRINT);
	

	return (0);
}
