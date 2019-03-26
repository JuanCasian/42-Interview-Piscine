/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:24:16 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 14:24:16 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
	int low;
	int high;
	int mid;
	char *guess;
	int res;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = arts[mid]->name;
		res = strcmp(guess, name);
		if (res == 0)
			return (arts[mid]->price);
		if (res > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}
