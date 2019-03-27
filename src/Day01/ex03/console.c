/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:24:46 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 19:24:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *initStack()
{
	struct s_stack	*res;

	if (!(res = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return (NULL);
	res->item = NULL;
	return (res);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item;

	if (!stack)
		return ;
	if (!(item = (struct s_item*)malloc(sizeof(struct s_item))))
		return ;
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

int pop(struct s_stack *stack)
{
	struct s_item 	*res;
	int				idx;

	if (!stack || !stack->item)
		return (-1);
	res = stack->item;
	stack->item = stack->item->next;
	idx = res->idx;
	free(res);
	return (idx);
}

char *console(void)
{
	char			*res;
	char			*buf;
	int				i;
	int				idx;
	int				read;
	
	struct s_stack	*stack;

	if (!(res = (char*)calloc(LEN + 1, sizeof(char))) ||
			!(buf = (char*)calloc(LEN + 1, sizeof(char))) || !(stack = initStack()))
		return (NULL);
	idx = 0;
	i = 0;
	while (1)
	{
		printf("?: ");
		memset(buf, 0, LEN);
		buf = gets(buf);
		read = (int)strlen(buf);
		if (!strncmp(buf, "UNDO", 4))
		{
			idx = pop(stack);
			memset(&res[idx], 0, LEN - idx);
			i = idx;
		}
		else if (!strncmp(buf, "SEND", 4))
		{
			free(buf);
			while (stack->item)
				pop(stack);
			free(stack);
			return (res);
		}
		else
		{
			push(stack, i);
			strcat(res, buf);
			strcat(res, " ");
			i += read + 1;
		}
		printf("%s\n\n", res);
	}
}

