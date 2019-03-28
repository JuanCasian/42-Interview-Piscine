/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:26:06 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/27 14:26:06 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	if (!(queue = (struct s_queue*)malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

struct s_node *dequeue(struct s_queue *queue)
{
	struct s_item *tmp;
	struct s_node *res;

	if (!queue || !queue->first)
		return (NULL);
	tmp = queue->first;
	if (queue->first == queue->last)
		queue->last = queue->last->next;
	queue->first = queue->first->next;
	res = tmp->node;
	free(tmp);
	return (res);
}

void enqueue(struct s_queue *queue, struct s_node *node)
{
	struct s_item *item;

	if (!(item = (struct s_item*)malloc(sizeof(struct s_item))))
		return ;
	item->node = node;
	item ->next = NULL;
	if (!queue->first)
	{
		queue->first = item;
		queue->last = item;
		return ;
	}
	queue->last->next = item;
	queue->last = item;
}

struct s_node *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->node);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

struct s_item *add_visit(struct s_item *head, struct s_node *n)
{
	struct s_item *tmp;

	if (!n || !(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
		return (NULL);
	tmp->parent = NULL;
	tmp->node = n;
	tmp->next = NULL;
	if (!head)
		return (tmp);
	tmp->next = head;
	return (tmp);
}

int	visited(struct s_node *node, struct s_item *vis)
{
	struct s_item *tmp;

	if (!vis)
		return (0);
	tmp = vis;
	while (tmp)
	{
		if (tmp->node == node)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

struct s_item *add_parent(struct s_item *head, struct s_node *n, struct s_node *parent)
{
	struct s_item *tmp;

	if (head && n)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->node == n)
			{
				tmp->parent = parent;
				return (head);
			}
			tmp = tmp->next;
		}
	}
	if (!n || !(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
		return (NULL);
	tmp->parent = parent;
	tmp->node = n;
	tmp->next = NULL;
	if (!head)
		return (tmp);
	tmp->next = head;
	return (tmp);
}

struct s_node *get_parent(struct s_item *head, struct s_node *son, int *found)
{
	struct s_item *tmp;

	if (!son || !head)
		exit(-1);
	tmp = head;
	while (tmp)
	{
		if (tmp->node == son)
		{
			*found = 1;
			return (tmp->parent);
		}
		tmp = tmp->next;
	}
	*found = 0;
	return (NULL);
}

int	count_steps(struct s_item *head, struct s_node *final)
{
	int				found_par;
	int				steps;

	steps = 0;
	found_par = 0;
	while ((final = get_parent(head, final, &found_par)) && found_par == 1)
		steps++;
	if (found_par == 1)
		return (steps);
	return (0);

}

int	minimumMoves(struct s_node *begin)
{
	struct s_queue	*q;
	struct s_node	*cur;
	struct s_item	*vis;
	struct s_item	*parents;

	vis = NULL;
	parents = NULL;
	if (!(q = queueInit()))
		return (-1);
	enqueue(q, begin);
	if (!(parents = add_parent(parents, begin, NULL)))
		return (-1);
	while (!isEmpty(q))
	{
		cur = dequeue(q);
		if (cur->isFinal)
			return (count_steps(parents, cur));
		else if (!visited(cur, vis))
		{
			if (cur->next && !visited(cur->next, vis))
			{
				if (!(parents = add_parent(parents, cur->next, cur)))
					return (-1);
				enqueue(q, cur->next);
			}
			if (cur->random && !visited(cur->random, vis))
			{
				if (!(parents = add_parent(parents, cur->random, cur)))
					return (-1);
				enqueue(q, cur->random);
			}
		}
		if (!(vis = add_visit(vis, cur)))
			return (-1);
	}
	return (-1);
}
