/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:41:40 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/05 20:41:40 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(struct s_art *a, struct s_art *b)
{
	struct s_art tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(struct s_art **masterpiece, int n, int i)
{
	int biggest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && strcmp(masterpiece[l]->name,masterpiece[biggest]->name) > 0)
		biggest = l;
	if (r < n && strcmp(masterpiece[r]->name,masterpiece[biggest]->name) > 0)
		biggest = r;
	if (biggest  != i)
	{
		swap(masterpiece[i], masterpiece[biggest]);
		heapify(masterpiece, n , biggest);
	}
}

void heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i , 0);
	}
}
