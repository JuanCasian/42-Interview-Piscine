/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:27:45 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/01 18:27:45 by jcasian          ###   ########.fr       */
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

char *rightShift(char *bin, int k)
{
	char first;
	int j;

	first = bin[0];
	for (int i = 0; i < k; i++)
	{
		for (j = 5; j > 0; j--)
			bin[j] = bin[j - 1];
		bin[j] = first;
	}
	return (bin);
}

char *leftShift(char *bin, int k)
{
	int j;

	for (int i = 0; i < k; i++)
	{
		for (j = 0; j < 5; j++)
			bin[j] = bin[j + 1];
		bin[j] = '0';
	}
	return (bin);
}

int toInt(char *bits)
{
	int res;
	int multiplier;
	int neg;
	char *buf;

	res = 0;
	neg = 0;

	buf = getSum(bits, "0000000");
	if (bits[0] == '1')
	{	
		neg = 1;
		for (int j = 0; j < 6; j++)
			buf[j] = bits[j] == '0' ? '1' : '0';
		buf = getSum(buf, "000001");
	}
	multiplier = 1;
	for (int i = 5; i >= 1; i--)
	{
		res += ((int)buf[i] - '0') * multiplier;
		multiplier = multiplier * 2;
	}
	if (neg)
		return (-res);
	return (res);
}

