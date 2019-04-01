/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:15:59 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/30 13:15:59 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *new_node(int val)
{
	struct s_node *node;

	if (!(node = (struct s_node*)calloc(1, sizeof(struct s_node))))
		return (NULL);
	node->value = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

struct s_node *createBSTU(int *arr, int start, int end)
{
	struct s_node *root;
	int mid;

	if (start > end)
		return (NULL);
	mid = start + (end - start) / 2;
	if (!(root = new_node(arr[mid])))
	{
		printf("Error creating new node\n");
		return (NULL);
	}
	root->left = createBSTU(arr, start, mid - 1);
	root->right = createBSTU(arr, mid + 1, end);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	return (createBSTU(arr, 0, n - 1));
}
