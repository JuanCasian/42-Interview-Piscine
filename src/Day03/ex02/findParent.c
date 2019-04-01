/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:50:37 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/30 18:50:37 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
struct s_item {
	struct s_node *node;
	struct s_item *up;
	struct s_item *down;
};

struct s_stack {
	struct s_item *node;
	struct s_item *top;
	struct s_item *bottom;
};

struct s_stack *init_stack(void)
{
	struct s_stack *stack;

	if (!(stack = (struct s_stack*)calloc(1, sizeof(struct s_stack))))
	{
		printf("Error allocating memory for stack\n");
		return (NULL);
	}
	stack->node = NULL;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

int push(struct s_stack *s, struct s_node *node)
{
	struct s_item *item;

	if (!(item = (struct s_item*)calloc(1, sizeof(struct s_item))))
	{
		printf("Error allocating memory for stack item\n");
		return (0);
	}
	item->node = node;
	item->down = s->top;
	if (s->top)
		s->top->up = item;
	item->up = NULL;
	if (!s->bottom)
		s->bottom = item;
	s->top = item;
	return (1);
}

struct s_node *pop(struct s_stack *s)
{
	struct s_item *tmp;
	struct s_node *res;

	if (!s->top)
		return (NULL);
	if (s->top == s->bottom)
		s->bottom = NULL;
	tmp = s->top;
	s->top = tmp->down;
	res = tmp->node;
	free(tmp);
	return (res);
}

struct s_node	*dfs(struct s_stack *s, struct s_node *root, char *val)
{
	struct s_node *res;

	if (!root)
		return (NULL);
	if (!(push(s, root)))
	{
		printf("Error pushing to stack\n");
		return(NULL);
	}
	if (!strcmp(root->name, val))
		return (root);
	if (!root->children)
		return (NULL);
	for (int i = 0; root->children[i]; i++)
	{
		if ((res = dfs(s, root->children[i], val)))
			return (res);
	}
	if (!pop(s))
	{
		printf("Error poping from stack\n");
		return(NULL);
	}
	return (NULL);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_stack	*s1;
	struct s_stack	*s2;
	struct s_item	*tmp1;
	struct s_item	*tmp2;
	struct s_node	*res;

	if (!(s1 = init_stack()) || !(s2 = init_stack()))
		return (NULL);
	if (!dfs(s1, root, firstSpecies) || !dfs(s2, root, secondSpecies))
		return (NULL);
	tmp1 = s1->bottom;
	tmp2 = s2->bottom;
	res = NULL;
	while (tmp1 && tmp2 && tmp1->node == tmp2->node)
	{
		res = tmp1->node;
		tmp1 = tmp1->up;
		tmp2 = tmp2->up;
	}
	return (res);
}
