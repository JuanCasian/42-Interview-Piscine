/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatWasThat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:21:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 15:21:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*ft_strnew(size_t n)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (i <= n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char    *delete(char *word, int pos)
{
	size_t len;

	len = strlen(word);
	if (pos >= (int)len)
		return (NULL);
	while (word[pos])
	{
		word[pos] = word[pos + 1];
		pos++;
	}
	return (word);
}

char    *replace(char *word, int pos, char c)
{
	if (pos >= (int)strlen(word))
		return (NULL);
	word[pos] = c;
	return (word);
}

char    *add(char *word, int pos, char c)
{
	int 	i;
	int 	j;
	size_t	len;
	char	*res;

	len = strlen(word);
	if (pos >= (int)len)
		return (NULL);
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (word[i])
	{
		if (i == pos)
		{
			res[j] = c;
			j++;
		}
		res[j] = word[i];
		i++;
		j++;
	}
	return (res);
}

char	*whatWasThat(char *word, char **dict)
{
	int difs[3];
	int chars[3][257];
	int i;
	int j;
	int min;
	int add;
	int repla;

	i = -1;
	while (++i < 3)
	{
		difs[i] = 0;
		j = -1;
		while (++j < 257)
			chars[i][j] = 0;
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (dict[i][++j])
			chars[i][(int)dict[i][j]] += 1;
		j = -1;
		while (word[++j])
			chars[i][(int)word[j]] -= 1;
			j = -1;
		while (++j < 257)
			difs[i] += abs(chars[i][j]);
	}
	min = difs[0];
	j = 0;
	i = -1;
	while (++i < 3)
	{
		if (min > difs[i])
		{
			j = i;
			min = difs[i];
		}
	}
	add = abs((int)strlen(word) - (int)strlen(dict[j]));
	repla = abs(min - add) / 2;
	min = add + repla;
	if (min > DEPTH)
		return (NULL);
	return (dict[j]);
}
