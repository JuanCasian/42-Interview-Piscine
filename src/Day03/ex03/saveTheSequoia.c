/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:47:27 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/30 19:47:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_maxheap {
	struct s_node **harr;
	int capacity;
	int	heap_size;
}				t_maxheap;

void	swap(struct s_node **x, struct s_node **y)
{
	struct s_node *tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
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

t_maxheap	*new_MaxHeap(int capacity)
{
	t_maxheap *res;
	
	if (!(res = (t_maxheap*)calloc(1,sizeof(t_maxheap))) ||
		!(res->harr = (struct s_node**)calloc(capacity + 1, sizeof(struct s_node*))))
		return (NULL);
	res->heap_size = 0;
	res->capacity = capacity;
	return (res);
}

void mh_insert(t_maxheap *heap, struct s_node *k)
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

	while (i != 0 && heap->harr[get_parent(i)]->value < heap->harr[i]->value)
	{
		swap(&(heap->harr[i]), &(heap->harr[get_parent(i)]));
		i = get_parent(i);
	}
}

int 			get_numElements(struct s_node *root)
{
	if (!root)
		return (0);
	return (get_numElements(root->left) + 1 + get_numElements(root->right));
}

void	fill_heap(t_maxheap *heap, struct s_node *root)
{
	if (!root)
		return;
	mh_insert(heap, root);
	fill_heap(heap, root->left);
	fill_heap(heap, root->right);
}

void	saveTheSequoia(struct s_node **root)
{
	t_maxheap *heap;
	int left_index;
	int right_index;

	if (!(heap = new_MaxHeap(get_numElements(*root))))
	{
		printf("Error initializing heap\n");
		return ;
	}
	fill_heap(heap, *root);
	for (int i = 0; i < heap->heap_size; i++)
	{
		left_index = get_left(i);
		right_index = get_right(i);
		heap->harr[i]->left = left_index < heap->heap_size ? heap->harr[left_index] : NULL;
		heap->harr[i]->right = right_index < heap->heap_size ? heap->harr[right_index] : NULL;
	}
	*root = heap->harr[0];
	free(heap->harr);
	free(heap);
}
