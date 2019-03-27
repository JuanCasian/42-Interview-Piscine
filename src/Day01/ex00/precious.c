/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:05:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 18:05:31 by jcasian          ###   ########.fr       */
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

static struct s_node	*insert_node(struct s_node *head, char c)
{
	struct s_node *tmp;
	
	if (!(tmp = (struct s_node*)malloc(sizeof(struct s_node))))
		return (NULL);
	tmp->c = c;
	if (!head)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		return (tmp);
	}
	tmp->next = head;
	tmp->prev = head->prev;
	head->prev->next = tmp;
	head->prev = tmp;
	return (head);
}

char *precious(int *text, int size)
{
	struct s_node	*head;
	int				i;
	char			*str;
	int				counter;

	head = NULL;
	str = CS;
	i = -1;
	while (str[++i])
		if (!(head = insert_node(head, str[i])))
		{
			printf("Error inserting node\n");
			return (NULL);
		}
	if (!(str = ft_strnew((size_t)size)))
	{
		printf("Error creating new string for result\n");
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		counter = text[i];
		while (counter != 0)
		{
			if (counter > 0)
			{
				head = head->next;
				counter--;
			}
			else if (counter < 0)
			{
				head = head->prev;
				counter++;
			}
		}
		str[i] = head->c;
	}
	return (str);
}
