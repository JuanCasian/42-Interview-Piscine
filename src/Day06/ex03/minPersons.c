/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:34 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/04 15:26:34 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		minPersons(int elements, int minPercentage)
{
	double elem = (double)elements;
	double goal = (double)minPercentage / 100;
	int people = 1;
	double prob_unique_com = (elem - people + 1) / elem;
	double prob_not_unique = 1 - prob_unique_com;
	while (prob_not_unique < goal)
	{
		people += 1;
		prob_unique_com *= (elem - people + 1) / elem;
		prob_not_unique = 1 - prob_unique_com;
	}
	return (people);
}
