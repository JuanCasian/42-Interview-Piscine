/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:17:54 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/01 16:17:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *check_not(char *bits)
{
	if (bits[0] == '~')
	{
		bits++;
		for (int i = 0; i < 4; i++)
		{
			if (bits[i] == '0')
				bits[i] = '1';
			else
				bits[i] = '0';
		}
	}
	return (bits);
}

char *getAnd(char *a, char *b)
{
	char *res;

	if (!(res = (char*)calloc(5, sizeof(char))))
		return (NULL);
	a = check_not(a);
	b = check_not(b);
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == '1' && b[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
	}
	return (res);
}

char *getOr(char *a, char *b)
{
	char *res;

	if (!(res = (char*)calloc(5, sizeof(char))))
		return (NULL);
	a = check_not(a);
	b = check_not(b);
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == '1' || b[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
	}
	return (res);
}

int toInt(char *bits)
{
	int res;
	int multiplier;

	bits = check_not(bits);
	res = 0;
	multiplier = 1;
	for (int i = 3; i >= 0; i--)
	{
		res += ((int)bits[i] - '0') * multiplier;
		multiplier = multiplier * 2;
	}
	return (res);
}

