/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:32:28 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/26 18:32:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	if (lst->next == NULL)
	{
		printf("%s", lst->word);
		return ;
	}
	printReverse(lst->next);
	printf(" %s", lst->word);
}
