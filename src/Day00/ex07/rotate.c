/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:08:53 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 14:08:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate(int **picture, int n)
{
	int tmp;

	for (int x = 0; x < n / 2; x++)
	{
		for (int y = x; y < n - x - 1; y++)
		{
			tmp = picture[x][y]; // top left - top left
			picture[x][y] = picture[n - 1 - y][x]; //top left - bottom left
			picture[n - 1 - y][x] = picture[n - 1 - x][n - 1 - y]; //bottom-left - bottom right 
			picture[n - 1 - x][n - 1 - y] = picture[y][n  -  1  -  x];  //bottom right -  bottom left
			picture[y][n  -  1  -  x] = tmp; // bottom left - top left
		}
	}
}