/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:55:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/01 18:55:32 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getXor(char *a, char *b)
{
	for (int i = 0; i < 6; i++)
	{
		if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
			a[i] = '1';
		else
			a[i] = '0';
	}
	return (a);
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
