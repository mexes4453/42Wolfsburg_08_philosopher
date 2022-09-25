/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:27:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 08:27:21 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_UTILS_H
# define QUEUE_UTILS_H
# include <stdlib.h>
# include <string.h>

typedef struct s_queue
{
	pthread_mutex_t	mtx;
	int				head;
	int				tail;
	int				sz;
	int				len;
	void			*data;
}					t_queue;

t_queue	*ft_queue_create(int sz);
int		ft_queue_pop(t_queue *q, int *data);
int		ft_queue_enqueue(t_queue *q, int nbr);
int		ft_queue_is_empty(t_queue *q);
void	ft_queue_del(t_queue *q);
#endif
