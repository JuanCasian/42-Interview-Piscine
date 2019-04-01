/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:19:40 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/29 19:19:40 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#define INT_MIN -2147483648

int				get_max(struct s_node *root)
{
	int curr;
	int max_left;
	int max_right;
	int max;

	if (!root)
		return (INT_MIN);
	curr = root->value;
	max_left = get_max(root->left);
	max_right = get_max(root->right);
	max = max_right;
	if (max_left > max_right)
		max = max_left;
	if (curr > max)
		max = curr;
	return (max);
}

int				get_min(struct s_node *root)
{
	int curr;
	int min_left;
	int min_right;
	int min;

	if (!root)
		return (__INT_MAX__);
	curr = root->value;
	min_left = get_min(root->left);
	min_right = get_min(root->right);
	min = min_right;
	if (min_left < min_right)
		min = min_left;
	if (curr < min)
		min = curr;
	return (min);
}

int 			get_numElements(struct s_node *root)
{
	if (!root)
		return (0);
	return (get_numElements(root->left) + 1 + get_numElements(root->right));
}

int				get_height(struct s_node *root)
{
	int left_depth;
	int right_depth;

	if (!root)
		return (0);
	left_depth = get_height(root->left);
	right_depth = get_height(root->right);
	if (left_depth > right_depth)
		return (left_depth + 1);
	return (right_depth + 1);
	
}

int				is_BST(struct s_node *root, int min, int max)
{
	if (!root)
		return (1);
	if (root->value < min || root->value > max)
		return (0);
	if (is_BST(root->left, min, root->value) && is_BST(root->right, root->value + 1, max))
		return (1);
	return (0);
}

int				is_balanced(struct s_node *root)
{
	int left_height;
	int right_height;

	if (!root)
		return (1);
	left_height = get_height(root->left);
	right_height = get_height(root->right);

	if (abs(left_height - right_height) <= 1 &&
		is_balanced(root->left) && is_balanced(root->right))
		return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info	info;

	info.min = get_min(root);
	info.max = get_max(root);
	info.elements = get_numElements(root);
	info.height = get_height(root);
	info.isBST = is_BST(root, INT_MIN, __INT_MAX__);
	info.isBalanced = is_balanced(root);
	return (info);
}
