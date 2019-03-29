/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:21:48 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 18:21:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Divide the array by half and check which side of the array is sorted
// Then on the sorted side it checks if the value is on that side, if it is then
// the calls the binary seach on that side, else the value should be on the unsorted side


//Recursive version
// int binarySearch(int *rocks, int low, int high, int value)
// {
// 	int mid;

// 	if (low > high)
// 		return (-1);
// 	mid = (low + high) / 2;
// 	if (rocks[mid] == value)
// 		return (mid);
// 	if (rocks[low] <= rocks[mid])
// 	{
// 		if (value >= rocks[low] && value <= rocks[mid])
// 			return (binarySearch(rocks, low, mid - 1, value));
// 		return (binarySearch(rocks, mid + 1, high, value));
// 	}
// 	if (value >= rocks[mid] && value <= rocks[high])
// 		return (binarySearch(rocks, mid + 1, high, value));
// 	return (binarySearch(rocks, low, mid - 1, value));

// }

int	searchShifted(int *rocks, int length, int value)
{
	int low;
	int high;
	int mid;

	if (!rocks)
		return (-1);
	low = 0;
	high = length - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (rocks[mid] == value)
			return (mid);
		if (rocks[low] <= rocks[mid])
		{
			if (value >= rocks[low] && value <= rocks[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if (value >= rocks[mid] && value <= rocks[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	for (int i = 0; i < length; i++)
		if (rocks[i] == value)
			return (i);
	return (-1);
}
