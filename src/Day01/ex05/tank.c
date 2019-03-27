/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:54:36 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 20:54:36 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *initStack()
{
	struct s_stack	*res;

	if (!(res = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return (NULL);
	res->elem = NULL;
	res->sum = 0;
	return (res);
}

void push(struct s_stack *stack, int energy)
{
	struct s_elem *elem;

	if (!stack)
		return ;
	if (!(elem = (struct s_elem*)malloc(sizeof(struct s_elem))))
		return ;
	elem->energy = energy;
	elem->next = stack->elem;
	stack->elem = elem;
	stack->sum += energy;
}

int pop(struct s_stack *stack)
{
	struct s_elem 	*res;
	int				energy;

	if (!stack || !stack->elem)
		return (-1);
	res = stack->elem;
	stack->elem = stack->elem->next;
	energy = res->energy;
	free(res);
	return (energy);
}

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	if (!(tank = (struct s_tank*)malloc(sizeof(struct s_tank))))
		return (NULL);
	tank->n = 0;
	tank->stacks = NULL;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_stack *s;

	if (!tank)
		return ;
	if (!tank->stacks)
	{
		if (!(tank->stacks = (struct s_stack**)malloc(sizeof(struct s_stack*)))||
				!(s = initStack()))
			return ;
		tank->stacks[0] = s;
		tank->n = 1;
		push(s, energy);
		return ;
	}
	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
	{
		if (!(tank->stacks = (struct s_stack**)realloc(tank->stacks, sizeof(struct s_stack**) * (tank->n + 1))))
			return ;
		if (!(tank->stacks[tank->n] = initStack()))
			return ;
		tank->n += 1;
		push(tank->stacks[tank->n - 1], energy);
		return ;
	}
	else
		push(tank->stacks[tank->n - 1], energy);
}

int tankPop(struct s_tank *tank)
{
	int res;

	if (!tank || tank->n == 0)
		return (-1);
	if ((res = pop(tank->stacks[tank->n - 1])) == -1)
	{
		free(tank->stacks[tank->n - 1]);
		tank->n -= 1;
		if (!(tank->stacks = (struct s_stack**)realloc(tank->stacks, sizeof(struct s_stack*) * tank->n)))
			return (-1);
		return (tankPop(tank));
	}
	else
		return (res);
}
