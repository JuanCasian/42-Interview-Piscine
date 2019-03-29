/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:17:04 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 19:17:04 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MAX_DIGITS 7

int getDescription(struct s_info *info)
{
	int res;

	res = 0;
	res += info->gender * 100000;
	res += info->height * 10000;
	res += info->hairColor * 1000;
	res += info->eyeColor * 100;
	res += info->tattoo * 10;
	res += info->piercing;
	return (res);
}

void count_sort(struct s_criminal **criminals, int len, int divider)
{
	struct s_criminal	**output;
	int					*index;
	int					i;
	int					val;

	if (!(output = (struct s_criminal**)calloc(len + 1, sizeof(struct s_criminal))) ||
		!(index = (int*)calloc(10, sizeof(int))))
	{
		printf("Error allocating memory for buffers");
		return ;
	}
	for (i = 0; i < len; i++)
	{
		val = criminals[i]->description;
		index[(val / divider) % 10] += 1;
	}
	for (i = 1; i < 10; i++)
		index[i] += index[i -1 ];
	for (i = len - 1; i >= 0; i--)
	{
		val = criminals[i] -> description;
		output[index[(val / divider) % 10] - 1] = criminals[i];
		index[(val / divider) % 10] -= 1;
	}
	for (i = 0; i < len; i++)
		criminals[i] = output[i];
}

void sortCriminals(struct s_criminal **criminals)
{
	int digit_i;
	int len;

	len = 0;
	digit_i = 1;
	while(criminals[len])
		len++;
	for (int i = 0; i < MAX_DIGITS; i++)
	{
		count_sort(criminals, len, digit_i);
		digit_i *= 10;
	}
}

int get_right_pos(struct s_criminal **criminals, int left, int right, int value)
{
	int middle;

	while (right - left > 1)
	{
		middle = left + (right - left) / 2;
		if (criminals[middle]->description <= value)
			left = middle;
		else
			right = middle;
	}
	return (left);
}

int get_left_pos(struct s_criminal **criminals, int left, int right, int value)
{
	int middle;

	while (right - left > 1)
	{
		middle = left + (right - left) / 2;
		if (criminals[middle]->description >= value)
			right = middle;
		else
			left = middle;
	}
	return (right);
}

int binary_search(struct s_criminal **criminals, int low, int high, int value)
{
	int mid;
	int res;

	while (low <= high)
	{
		mid = (low + high) / 2;
		res = criminals[mid]->description;
		if (res == value)
			return (mid);
		if (res > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int l_pos;
	int r_pos;
	int len;
	int	val;
	struct s_criminal **res;
	int j;
	
	len = 0;
	while(criminals[len])
		len++;
	val = getDescription(info);
	r_pos = get_right_pos(criminals, 0, len - 1, val);
	l_pos = get_left_pos(criminals, 0, len - 1, val);
	if (criminals[l_pos]->description == val && criminals[r_pos]->description == val)
	{
		if (!(res = (struct s_criminal**)calloc((size_t)(r_pos - l_pos + 1), sizeof(struct s_criminal*))))
		{
			printf("Error alocating memory of the array");
			return (NULL);
		}
		j = 0;
		for (int i = l_pos; i <= r_pos; i++)
		{
			res[j] = criminals[i];
			j++;
		}
	}
	else
	{
		if (!(res = (struct s_criminal**)calloc(1, sizeof(struct s_criminal*))))
		{
			printf("Error alocating memory of the array");
			return (NULL);
		}
	}
	return (res);
}

