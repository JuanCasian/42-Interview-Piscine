/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:51:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/04 09:51:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int myabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double probaDistance(int dist, int *locations, int n)
{
	double total = 0;
	double close = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			total++;
			if (myabs(locations[i] - locations[j]) > dist)
				close++;
		}
	}
	return (close/total);
}
