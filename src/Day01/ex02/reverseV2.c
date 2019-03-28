/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:40:58 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 18:40:58 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack	*res;

	if (!(res = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return (NULL);
	res->item = NULL;
	return (res);
}

void *pop(struct s_stack *stack)
{
	struct s_item *res;

	if (!stack || !stack->item)
		return (NULL);
	res = stack->item;
	stack->item = stack->item->next;
	return (res);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *item;

	if (!stack)
		return ;
	if (!(item = (struct s_item*)malloc(sizeof(struct s_item))))
		return ;
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack 	*stack;
	struct s_node	*tmp;
	struct s_item	*res;
	int				flag;

	flag = 0;
	if (!(stack = stackInit()))
	{
		printf("Error creating the stack\n");
		return ;
	}
	tmp = lst;
	while (tmp)
	{
		push(stack, tmp->word);
		tmp = tmp->next;
	}
	while ((res = pop(stack)))
	{
		if (flag == 0)
		{
			printf("%s", res->word);
			flag = 1;
		}
		else
			printf(" %s", res->word);
	}
}
