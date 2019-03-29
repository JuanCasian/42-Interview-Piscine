/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:36:33 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/27 20:36:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	fill_arr(struct s_stone *head, struct s_group **gs, int n_gs)
{
	int		i;
	int		curr;

	i = 0;
	curr = head->size;
	while (i < n_gs)
	{
		if (!(gs[i] = (struct s_group*)calloc(1, sizeof(struct s_group))))
			return (0);
		gs[i]->first = head;
		while (head->next && head->next->size == curr)
			head = head->next;
		gs[i]->last = head;
		gs[i]->size = curr;
		i++;
		head = head->next;
		if (head)
			curr = head->size;
	}
	return (1);
}

int	new_group_arr(struct s_stone *stone, struct s_group ***head)
{
	int				n_groups;
	int				curr;
	struct s_stone	*tmp;
	struct s_group	**gs;

	tmp = stone;
	n_groups = 1;
	curr = tmp->size;
	while (tmp)
	{
		if (tmp->size != curr)
		{
			curr = tmp->size;
			n_groups++;
		}
		tmp = tmp->next;
	}
	if (!(gs = (struct s_group**)calloc((size_t)n_groups + 1, sizeof(struct s_group*))))
		return (-1);
	*head = gs;
	return (n_groups);
}

void sortStones(struct s_stone **stone)
{
	struct s_group	**gs;
	struct s_group	*gtmp;
	int				n_gs;
	int				swapped;


	if ((n_gs = new_group_arr(*stone, &gs)) == -1)
		return ;
	if (!(fill_arr(*stone, gs , n_gs)))
		return ;
	for (int i = 0; i < n_gs - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < n_gs - i - 1; j++)
		{
			if (gs[j]->size > gs[j + 1]->size)
			{
				gtmp = gs[j];
				gs[j] = gs[j + 1];
				gs[j + 1] = gtmp;
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
	*stone = gs[0]->first;
	for (int h = 0; h < n_gs - 1; h++)
	{
		gs[h]->last->next = gs[h + 1]->first;
		free(gs[h]);
	}
	gs[n_gs - 1]->last->next = NULL;
	free(gs[n_gs - 1]);
	free(gs);
}
