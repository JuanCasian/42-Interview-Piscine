/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:01:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 21:01:43 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	youngest(int *ages, int left, int right)
{
	int mid;
	int val1;
	int val2;

	if (right - left >= 2)
	{
		mid = left + (right - left) / 2;
		val1 = youngest(ages, left, mid);
		val2 = youngest(ages, mid + 1, right);
		if (val1 < val2)
			return (val1);
		else
			return (val2);
	}
	else if (right - left == 0)
	{
		return (ages[left]);
	}
	else
	{
		if (ages[left] < ages[right])
			return (ages[left]);
		else
			return (ages[right]);
	}

}

void printYoungest(int *ages, int length)
{
	int min;

	min = youngest(ages, 0, length - 1);
	printf("Younges : %i\n", min);
}
