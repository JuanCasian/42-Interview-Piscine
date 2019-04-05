/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:16:58 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/04 18:16:58 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define N 8

int getInitialPos(uint64_t board)
{
	int pos = -1;
	
	for (int i  = 0;  i < 64; i++)
	{
		if (board & 1)
		{
			if (pos == -1)
				pos = i;
			else
				return(-1);
		}
		board >>= 1;
	}
	return (pos);
}

int is_inside(int x, int y) 
{ 
    return (x >= 0 && x < N && y >= 0 && y < N); 
}

void print_prob(double **board)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
			printf("%f\t", board[i][k]);
		printf("\n");
	}
}

double ***create_probs(int steps)
{
	double ***res;

	if (!(res = (double***)calloc((size_t)steps + 1, sizeof(double**))))
		return (NULL);
	for (int i = 0; i <= steps; i++)
	{
		if (!(res[i] = (double**)calloc(N, sizeof(double*))))
			return (NULL);
		for (int j = 0; j < N; j++)
		{
			if (!(res[i][j] = (double*)calloc(N, sizeof(double))))
				return (NULL);
		}
	}
	return (res);
}

double probability_in(int start_x, int start_y, int steps)
{
	double ***probs;
	int mv_x[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
	int mv_y[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	double curr_prob;
	int curr_x;
	int curr_y;
	if (!(probs = create_probs(steps)))
		return (-1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			probs[0][i][j] = 1;
	for (int s = 1; s <= steps; s++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				curr_prob = 0;
				for (int move = 0; move < 8; move++)
				{
					curr_x = x + mv_x[move];
					curr_y = y + mv_y[move];
					if (is_inside(curr_x, curr_y))
						curr_prob += probs[s - 1][curr_y][curr_x] / 8;
				}
				probs[s][y][x] = curr_prob;
			}
		}
	}
	return (probs[steps][start_y][start_x]);
}

double knightOut(uint64_t board, int n)
{
	int pos;
	int start_x;
	int start_y;

	pos = getInitialPos(board);
	start_x = pos % 8;
	start_y = pos / 8;
	return (1 - probability_in(start_x, start_y, n));
}

