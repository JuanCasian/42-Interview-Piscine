/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:54:52 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 13:54:52 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void  sortArts(struct s_art **arts)
{
	int 			divider;
	int 			runner;
	struct s_art	*art_piece;

	divider = 0;
	while (arts[++divider])
	{
		art_piece = arts[divider];
		runner = divider - 1;
		while(runner >= 0 && (strcmp(art_piece->name, arts[runner]->name) < 0))
		{
			arts[runner + 1] = arts[runner];
			runner--;
		}
		arts[runner + 1] = art_piece;
	}
}
