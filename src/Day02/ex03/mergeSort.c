/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:59:14 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 14:59:14 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			merge(struct s_player **players, int left, int middle, int right)
{
	int left_lim = middle - left + 1;
	int right_lim = right - middle;
	int left_index,right_index,merged_index;
	struct s_player *left_arr[left_lim];
	struct s_player *right_arr[right_lim];

	/* Copy data to temp arrays L[] and R[] */
	for (int i = 0; i < left_lim; i++)
		left_arr[i] = players[left + i];
	for (int j = 0; j < right_lim; j++)
		right_arr[j] = players[middle + 1 + j];

	left_index = 0;
	right_index = 0;
	merged_index = left;
	while (left_index < left_lim && right_index < right_lim)
	{
		if (left_arr[left_index]->score >= right_arr[right_index]->score)
		{
			players[merged_index] = left_arr[left_index];
			left_index++;
		}
		else
		{
			players[merged_index] = right_arr[right_index];
			right_index++;
		}
		merged_index++;
	}
	/* Copy the remaining elements of L[], if there are any */
	while (left_index < left_lim)
	{
		players[merged_index] = left_arr[left_index];
		left_index++;
		merged_index++;
	}
 	/* Copy the remaining elements of R[], if there are any */
	while (right_index < right_lim)
	{
		players[merged_index] = right_arr[right_index];
		right_index++;
		merged_index++;
	}
}

void			mergeSortP(struct s_player **players, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		mergeSortP(players, left, middle);
		mergeSortP(players, middle + 1, right);
		merge(players, left, middle, right);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	int len;

	len = 0;
	while (players[len])
		len++;
	mergeSortP(players, 0, len - 1);
	return (players);
}
