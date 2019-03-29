/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:26:53 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 12:26:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insertionSort(struct s_player **players)
{
	int				divider;
	int				runner;
	struct s_player	*player;

	divider = 0;
	while(players[++divider])
	{
		player = players[divider];
		runner = divider - 1;
		while (runner >= 0 && player->score > players[runner]->score)
		{
			players[runner + 1] = players[runner];
			runner--;
		}
		players[runner + 1] = player;
	}
}
