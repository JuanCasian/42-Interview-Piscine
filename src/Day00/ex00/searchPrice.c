/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:28:23 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 12:28:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int  searchPrice(struct s_art **arts, char *name)
{
	int	i;

	i = -1;
	while (arts[++i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
	}
	return (-1);
}
