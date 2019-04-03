/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:25:33 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/01 21:25:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value)
		parkingRow = parkingRow | (1 << pos);
	else
		parkingRow = (~(1 << pos)) & parkingRow;
	return (parkingRow);
}
