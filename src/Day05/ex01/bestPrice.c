/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:41:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/03 13:41:00 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recurse(int pizzaSize, double *prices, double *max, double curr)
{
	if (!pizzaSize)
	{
		if (curr > *max)
			*max = curr;
	}
	else
	{
		for (int i = 1; i <= pizzaSize; i++)
			recurse(pizzaSize - i, prices, max, curr + prices[i]);
	}
}

double	bestPrice(int pizzaSize, double *prices)
{
	double max_price = 0;
	double curr;

	curr = 0;
	recurse(pizzaSize, prices, &max_price, curr);
	return (max_price);
}
