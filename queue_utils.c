/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:29:49 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 08:29:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_utils.h"

/**
 * @brief   This function allocates memory on the heap for the queue creation.
 *          It stores the address of the allocated memory on the passed in
 *          pointer address. 
 * 
 * @param sig_queue 
 * @return int 
 */
t_queue	*ft_queue_create(int sz)
{
	t_queue	*q;
	void	*d;

	d = NULL;
	q = (t_queue *)malloc(sizeof(t_queue) * 1);
	q->head = -1;
	q->tail = -1;
	q->len = 0;
	q->sz = sz;
	d = (void *)malloc(sizeof(int) * sz);
	if (d == NULL)
		return (NULL);
	memset(d, 0, sizeof(int) * sz);
	q->data = d;
	return (q);
}

/**
 * @brief 	This function checks if a queue stored with the type struct is
 * 			empty. It returns 0 if empty and -1 if not empty.
 * 
 * @param sd 
 * @return int 
 */
int	ft_queue_is_empty(t_queue *q)
{
	if ((q->head == -1) && (q->tail == -1))
		return (0);
	else if (q->len == 0)
		return (0);
	else
		return (-1);
}

/**
 * @brief 	This function is used by the handler to enqueue the received bit
 * 			in the queue stored within. 
 * 			It exits and returns -1 if the queue is full (rear == front).
 * 			If empty, it enqueues the recvd int and update the queue indexes
 * 			(front and rear) accordingly.
 * 
 * @param sd 
 * @param nbr 
 * @return int 
 */
int	ft_queue_enqueue(t_queue *q, int nbr)
{
	if ((q->tail == q->head) && q->len > 0)
		return (-1);
	if (ft_queue_is_empty(q) == 0)
	{
		q->head = 0;
		q->tail = 0;
		((int *)(q->data))[q->tail] = nbr;
		q->tail = (q->tail + 1) % q->sz;
		q->len++;
	}
	else
	{
		((int *)(q->data))[q->tail] = nbr;
		q->len++;
		q->tail = (q->tail + 1) % q->sz;
	}
	return (0);
}

/**
 * @brief 	This function dequeues the queue stored in type struct t_sigdata.
 * 			It exits and returns -1 if the queue is empty.
 * 			Then it checks if the item to be dequeued is the only one left.
 * 			If so, it is dequeue and the queue state is set to empty (front 
 * 			= rear = -1).
 * 			If there are more items in the queue, then the queue is dequeued
 * 			once and the indexes updated to point to the next item
 * 
 * @param sd 
 * @param nbr 
 * @return int 
 */
int	ft_queue_pop(t_queue *q, int *data)
{
	if (ft_queue_is_empty(q) == 0)
		return (-1);
	else if (q->head == q->tail && q->len > 0)
	{
		*data = ((int *)(q->data))[q->head];
		q->len--;
		(q->head) = (q->head + 1) % q->sz;
		return (0);
	}
	else
	{
		*data = ((int *)(q->data))[q->head];
		q->len--;
		(q->head) = (q->head + 1) % q->sz;
	}
	return (0);
}

void	ft_queue_del(t_queue *q)
{
	free(q->data);
	free(q);
}
/*
#include <stdio.h>
int main(void)
{
	t_queue q;
	int nbr;
	int idx = 0;

	ft_queue_create(&q, 3);
	while (++idx < 10)
	{
		printf("\nidx: %d", idx);
		if (ft_queue_enqueue(&q, idx) == -1)
			printf("\nError : enqueue");

	}
	while (ft_queue_pop(&q, &nbr) == 0)
	{
		printf("\nlen (%d) -> nbr (%d)", q.len, nbr);
	}
	idx = 3;
	while (++idx < 10)
	{
		printf("\nidx: %d", idx);
		if (ft_queue_enqueue(&q, idx) == -1)
			printf("\nError : enqueue");

	}
	while (ft_queue_pop(&q, &nbr) == 0)
	{
		printf("\nlen (%d) -> nbr (%d)", q.len, nbr);
	}
	return (0);

}
*/