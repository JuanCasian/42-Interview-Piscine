/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:39:29 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/28 21:39:29 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define INT_MIN -2147483648

void	swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

t_minheap	*new_MinHeap(int capacity)
{
	t_minheap *res;
	
	if (!(res = (t_minheap*)calloc(1,sizeof(t_minheap))) ||
		!(res->harr = (int*)calloc(capacity + 1, sizeof(int))))
		return (NULL);
	res->heap_size = 0;
	res->capacity = capacity;
}

int	get_parent(int i)
{
	return ((i - 1) / 2);
}

int get_left(int i)
{
	return (2 * i + 1);
}

int get_right(int i)
{
	return (2 * i + 2);
}

void mh_insert(t_minheap *heap, int k)
{
	int i;

	if (heap->heap_size  == heap->capacity)
	{
		printf("Heap overflow: could not insert key");
		return ;
	}
	heap->heap_size++;
	i = heap->heap_size - 1;
	heap->harr[i] = k;

	while (i != 0 && heap->harr[get_parent(i)] > heap->harr[i])
	{
		swap(&(heap->harr[i]), &(heap->harr[get_parent(i)]));
		i = get_parent(i);
	}
}

void mh_decreaseKey(t_minheap *heap, int i, int new_val)
{
	heap->harr[i] = new_val;
	while (i != 0 && heap->harr[get_parent(i)] > heap->harr[i])
	{
		swap(&(heap->harr[i]), &(heap->harr[get_parent(i)]));
		i = get_parent(i);
	}
}

void	mh_minHeapify(t_minheap *heap, int i)
{
	int left;
	int right;
	int smallest;

	left = get_left(i);
	right = get_right(i);
	smallest = i;
	if (left < heap->heap_size && heap->harr[left] < heap->harr[i])
		smallest = left;
	if (right < heap->heap_size && heap->harr[right] < heap->harr[smallest])
		smallest = right;
	if (smallest != i)
	{
		swap(&(heap->harr[i]), &(heap->harr[smallest]));
		mh_minHeapify(heap, smallest);
	}
}

int	mh_extractMin(t_minheap *heap)
{
	if (heap->heap_size <= 0)
		return (__INT_MAX__);
	if (heap->heap_size == 1)
	{
		heap->heap_size--;
		return (heap->harr[0]);
	}

	int root = heap->harr[0];
	heap->harr[0] = heap->harr[heap->heap_size -1];
	heap->heap_size--;
	mh_minHeapify(heap, 0);

	return (root);
}

void mh_delete(t_minheap *heap, int i)
{
	mh_decreaseKey(heap, i, INT_MIN);
	mh_extractMin(heap);

}


void externalSort(char *scoreFile, char *sortedFile, int ram)
{

}
