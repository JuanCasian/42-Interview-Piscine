/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:29:54 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 19:29:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define n_chars 256
#define PRIME 11

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

int	dictInsert(struct s_dict *dict, char *key, int value)
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
	tmp->value = value + 1;
	tmp->next = dict->items[index];
	dict->items[index] = tmp;
	return (1);
}

int	dictSearch(struct s_dict *dict, char *key)
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
	return (-1);
}

char *ft_strnew(size_t len)
{
	char	*res;
	size_t	i;

	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i <= len)
		res[i] = '\0';
	return (res);
}

int	appears(char *book, size_t low, struct s_dict *dict, int *extra, size_t book_len)
{
	struct s_item	*tmp;
	int				i;
	size_t			word_len;

	i = -1;
	while (++i < dict->capacity)
	{
		if (dict->items[i] != NULL)
		{
			tmp = dict->items[i];
			while (tmp)
			{
				word_len = strlen(tmp->key);
				*extra = (int)word_len;
				if (low + word_len < book_len &&  (!strncmp(&book[low], tmp->key, word_len - 1)))
					return (tmp->value);
				tmp = tmp->next;
			}
		}
	}
	return (-1);
}

char	*add_header(char *str, struct s_dict *dict, size_t book_len)
{
	struct s_item	*tmp;
	int				i;
	size_t			words_len;
	size_t			n_words;
	char			*res;
	int				flag;

	i = -1;
	words_len = 0;
	n_words = 0;
	while (++i < dict->capacity)
	{
		if (dict->items[i] != NULL)
		{
			tmp = dict->items[i];
			while (tmp)
			{
				n_words++;
				words_len += strlen(tmp->key);
				tmp = tmp->next;
			}
		}
	}
	if (!(res = ft_strnew(words_len + n_words + 2 + book_len)))
		return (NULL);
	res = strcat(res, "<");
	i = -1;
	flag = 0;
	while (++i < dict->capacity)
	{
		if (dict->items[i] != NULL)
		{
			tmp = dict->items[i];
			while (tmp)
			{
				if (!flag)
				{
					res = strcat(res, tmp->key);
					flag = 1;
				}
				else
				{
					res = strcat(res, ",");
					res = strcat(res, tmp->key);
				}
				tmp = tmp->next;
			}
		}
	}
	res = strcat(res, ">");
	res = strcat(res, str);
	return (res);
}

char *compress(char *book, struct s_dict *dict)
{
	char 	*new_txt;
	size_t		book_len;
	size_t		i;
	int		extra;
	int		index;
	int		j;
	char	*tmp;

	book_len = strlen(book);
	if (!(new_txt = ft_strnew(book_len)))
		return (NULL);
	j = 0;
	i = 0;
	while (i < book_len)
	{
		if ((index = appears(book, i, dict, &extra, book_len)) >= 0)
		{
			new_txt[j++] = '@';
			new_txt[j++] = (char)index;
			i += extra;
		}
		else
			new_txt[j++] = book[i++];
	}
	tmp = new_txt;
	new_txt = add_header(new_txt, dict, book_len);
	free(tmp);
	tmp = new_txt;
	new_txt = strdup(new_txt);
	free(tmp);
	return (new_txt);
}

