/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:59:52 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 14:59:52 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t hash(char *input)
{
	size_t	hash;
	size_t	c;

	hash = 5385;
	while ((c = (size_t)*input++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict	*dict;

	if (!(dict = (struct s_dict*)malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(dict->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity)))
	{
		free(dict);
		return (NULL);
	}
	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	dict->capacity = capacity;
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t			index;
	struct s_item	*tmp;

	index = hash(key) % (size_t)dict->capacity;
	tmp = dict->items[index];
	// while (tmp)
	// {
	// 	if (!strcmp(tmp->key, key))
	// 	{
	// 		tmp->value = value;
	// 		return (1);
	// 	}
	// 	tmp = tmp->next;
	// }
	if (!(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
		return (0);
	tmp->key = key;
	tmp->value = value;
	tmp->next = dict->items[index];
	dict->items[index] = tmp;
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	size_t			index;
	struct s_item	*tmp;

	index = hash(key) % (size_t)dict->capacity;
	tmp = dict->items[index];
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*item;

	if (!(item = dictSearch(dict, name)))
		return (-1);
	return (item->price);
}