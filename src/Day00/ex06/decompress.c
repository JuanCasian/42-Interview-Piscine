/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:29:39 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 12:29:39 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define STR_INIT_MEM 128

static int	count_strs(char *str, char c)
{
	int		n_strs;

	n_strs = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			n_strs++;
		while (*str != c && *str)
			str++;
	}
	return (n_strs);
}

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

char	*ft_strndup(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	n_strs;
	char	**res;
	size_t	i;
	size_t	k;

	k = 0;
	n_strs = count_strs((char*)s, c);
	if (!(res = (char**)malloc(sizeof(char*) * n_strs + 1)))
		return (NULL);
	while (k < n_strs)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (!(res[k] = ft_strndup((char*)s, i)))
			return (NULL);
		k++;
		while (*s != c && *s)
			s++;
	}
	res[k] = NULL;
	return (res);
}

struct s_string	*stringInit(void)
{
	struct s_string *string;

	if (!(string = (struct s_string*)malloc(sizeof(struct s_string) * STR_INIT_MEM)))
		return (NULL);
	string->capacity = STR_INIT_MEM;
	string->length = 0;
	if (!(string->content = ft_strnew(STR_INIT_MEM)))
	{
		free(string);
		return (NULL);
	}
	return (string);
}

int		stringAppend(struct s_string *s, char *add)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (add[i])
 	{
		if (s->length >= s->capacity)
		{
			tmp = s->content;
			if (!(s->content = ft_strnew((size_t)s->capacity * 2)))
			{
				s->content = tmp;
				return (0);
			}
			s->capacity = s->capacity * 2;
			s->content = strcpy(s->content, tmp);
			free(tmp);
		}
		s->content[s->length] = add[i];
		s->length += 1;
		i++;
	}
	return (1);
}		

char *decompress(char *cBook)
{
	struct s_string *s;
	int				i;
	char			**vals;
	int				j;
	int				index;

	if (!(s = stringInit()))
	{
		printf("Error createing the string\n");
		return (NULL);
	}
	i = 0;
	while (cBook[i] != '>')
		i++;
	cBook[i++] = '\0';
	if (!(vals = ft_strsplit(&cBook[1], ',')))
	{
		printf("Error spliting the header\n");
		return (NULL);
	}
	j = i;
	while (cBook[i])
	{
		while (cBook[i] && cBook[i] != '@')
			i++;
		if (cBook[i] && cBook[i] == '@')
		{
			cBook[i++] = '\0';
			index = ((int)cBook[i]) - 1;
			if (!stringAppend(s, &cBook[j]) || !stringAppend(s, vals[index]))
			{
				printf("Error appending string\n");
				return (NULL);
			}
			i++;
			j = i;
		}
	}
	if (j != i)
		if (!stringAppend(s, &cBook[j]))
		{
			printf("Error appending the last string\n");
			return (NULL);
		}
	return (s->content);
}