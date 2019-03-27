/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:37:08 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/27 13:37:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1) you create a copy of each node and you insert it between its original node and the next original
** 2) You copy the arbtrary nodes by: original->next->arbitrary = original->arbitrary->next
**	works because the next from the original is simpy a copy of the previous one
** 3) Restore the original linked list: original->next = original->next->next; copy->next = copy->next->next;
** 4) Add NULL to end of copy list
*/

#include "header.h"

struct s_node *new_node(int value)
{
	struct s_node *res;

	if (!(res = (struct s_node*)malloc(sizeof(struct s_node))))
		return (NULL);
	res->value = value;
	res->next = NULL;
	res->random = NULL;
	return (res);
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *tmp;
	struct s_node *runner;
	struct s_node *new_head;

	runner = node;
	while (runner)
	{
		if (!(tmp = new_node(runner->value)))
			return (NULL);
		tmp->next = runner->next;
		runner->next = tmp;
		runner = runner->next->next;
	}
	runner = node;
	while (runner)
	{
		if (runner->random)
			runner->next->random = runner->random->next;
		else
			runner->next->random = NULL;
		runner = runner->next->next;
	}
	runner = node;
	tmp = node->next;
	new_head = tmp;
	while (runner)
	{
		runner->next = runner->next->next;
		if (runner->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		runner = runner->next;
		tmp = tmp->next;
	}
	return (new_head);
}
