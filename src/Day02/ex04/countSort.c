/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:46:05 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 17:46:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define RANGE 256

void countSort(unsigned char *utensils, int n)
{
	int		*index;
	char	*output;
	int		i;
	
	if (!(output = (char*)calloc(n  + 1, sizeof(unsigned char))) ||
		!(index = (int*)calloc(RANGE + 1, sizeof(int))))
	{
		printf("Error allocating memory for buffers");
		return ;
	}
	for (i = 0; utensils[i]; i++)
		index[(int)utensils[i]] += 1;
	for (i = 1; i < RANGE + 1; i++)
		index[i] += index[i - 1];
	for (i = 0; utensils[i]; i++)
	{
		output[index[utensils[i]] - 1] = utensils[i];
		index[utensils[i]] -= 1;
	}
	for (i = 0; output[i]; i++)
		utensils[i] = output[i];
}
