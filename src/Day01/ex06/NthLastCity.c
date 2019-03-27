/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:16:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/27 13:16:31 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city	*main;
	struct s_city	*ref;
	int				i;

	if (!city)
		return (NULL);
	main = city;
	ref = main;
	i = 0;
	while (i++ <= n)
	{
		if (!ref)
			return (NULL);
		ref = ref->next;
	}
	while (ref)
	{
		ref = ref->next;
		main = main->next;
	}
	return (main->name);
}
