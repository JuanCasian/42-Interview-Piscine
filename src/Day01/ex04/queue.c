/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:27:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 20:27:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// fifo
struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	if (!(queue = (struct s_queue*)malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	char *res;
	struct s_node *tmp;

	if (!queue || !queue->first)
		return (NULL);
	tmp = queue->first;
	if (queue->first == queue->last)
		queue->last = queue->last->next;
	queue->first = queue->first->next;
	res = tmp->message;
	free(tmp);
	return (res);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new_node;

	if (!queue || !(new_node = (struct s_node*)malloc(sizeof(struct s_node))))
		return ;
	new_node->message = message;
	new_node->next = NULL;
	if (!queue->first)
	{
		queue->first = new_node;
		queue->last = new_node;
		return ;
	}
	queue->last->next = new_node;
	queue->last = new_node;
}

char *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}
