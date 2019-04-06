/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:19:19 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/04 10:19:19 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int count = 1;
	int prev = 0;

	for (int i = 1; hotspots[i]; i++)
	{
		if (hotspots[i]->pos - hotspots[i]->radius >= hotspots[prev]->pos + hotspots[prev]->radius)
		{
			prev = i;
			count++;
		}
		else if (hotspots[prev]->radius > 0)
			prev = i;
	}
	return (count);
}
