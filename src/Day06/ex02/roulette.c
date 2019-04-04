/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:03:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/04 11:03:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (nbGame < 0 || firstDollarsBet <= 0)
		return (0);
	if (firstDollarsBet >= dollarsWanted)
		return (1);
	else
		return ((18 * probabilityWin(2 * firstDollarsBet, dollarsWanted, nbGame - 1) + probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1)) / 37);
}
