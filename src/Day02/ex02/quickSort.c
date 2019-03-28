/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:00:41 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 13:00:41 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//swapper is going to be the last smaller when the partition finishes
//during the algorithm the swapper is the last smallest number index until, so when you find
	// another smalled you will put it in the next from that and then update the last smaller index

int partition(struct s_player **players, int low, int high)
{
	int pivot;
	int swapper;
	int compared;
	struct s_player	*tmp;

	pivot = players[high]->score;
	swapper = low - 1;
	compared = low;
	while (compared < high)
	{
		if (players[compared]->score <= pivot)
		{
			swapper++;
			tmp = players[compared];
			players[compared] = players[swapper];
			players[swapper] = tmp;
		}
		compared++;
	}
	tmp = players[high];
	players[high] = players[swapper + 1];
	players[swapper + 1] = tmp;
	return (swapper + 1);
}

void quickSortP(struct s_player **players, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(players, low, high);
		quickSortP(players, low, partition_index -1);
		quickSortP(players, partition_index + 1, high);
	}
}

void quickSort(struct s_player **players)
{
	int high;
	int low;

	high = 0;
	low = 0;
	while (players[high])
		high++;
	quickSortP(players, low, high - 1);
}
