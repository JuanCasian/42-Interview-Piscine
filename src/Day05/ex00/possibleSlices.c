/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:15:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/02 19:15:42 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recurse(struct s_array *arr, int n)
{
	struct s_array *copy;
	if (!n)
	{
		arrayPrint(arr);
		free(arr);
	}
	for (int i = n; i > 0; i--)
	{
		copy = arrayClone(arr);
		arrayAppend(copy, i);
		recurse(copy, n - i);
	}
}

void	printPossibleSlices(int pizzaSize)
{
	struct s_array *arr;

	arr = arrayInit();
	recurse(arr, pizzaSize);
}
