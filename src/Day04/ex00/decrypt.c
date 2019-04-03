/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:27:01 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/01 15:27:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getSum(char *a, char *b)
{
	int tmp;
	char *res;

	if (!(res = (char*)calloc(7, sizeof(char))))
		return (NULL);

	tmp = 0;
	for (int i = 5; i >= 0; i--)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			res[i] = '0' + tmp;
		}
		else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
		{
			if (tmp)
			{
				res[i] = '0';
				tmp = 1;
			}
			else
			{
				res[i] = '1';
				tmp = 0;
			}
		}
		else
		{
			res[i] = '0' + tmp;
			tmp = 1;
		}
	}
	return (res);
}

int toInt(char *bits)
{
	int res;
	int multiplier;

	res = 0;
	multiplier = 1;
	for (int i = 5; i >= 0; i--)
	{
		res += ((int)bits[i] - '0') * multiplier;
		multiplier = multiplier * 2;
	}
	return (res);
}

