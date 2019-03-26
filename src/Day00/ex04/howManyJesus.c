/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:44:15 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/25 15:44:15 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

#define n_chars 256
//Rabin-Karp algorithm
int howManyJesus(char *bible, char *jesus)
{
	int	pat_len, txt_len, pat_hash, txt_hash; //Algorithm necesary variables
	int hash_factor, prime; // hashing variables
	int i; // counters
	int n_appear; // counter of appearances

	pat_len = strlen(jesus);
	txt_len = strlen(bible);
	pat_hash = 0;
	txt_hash = 0;
	hash_factor = 1;
	prime = 11;
	n_appear = 0;

	// Calculate the hash_factor
	for (i = 0; i < pat_len - 1; i++)
		hash_factor = (hash_factor * n_chars) % prime;
	
	// Calculate the first hashing values of the pattern and the text window
	for (i = 0; i < pat_len; i++)
	{
		pat_hash = (n_chars*pat_hash + jesus[i]) % prime;
		txt_hash = (n_chars*txt_hash + bible[i]) % prime;
	}

	// Sliding part
	for (i = 0; i <= txt_len - pat_len; i++)
	{
		// If pattern and text hash values are the same then compare the strings
		if (pat_hash == txt_hash)
		{
			if (!strncmp(jesus, &bible[i], (size_t)pat_len))
				n_appear++;
		}

		// If there is still space for more window sliding then recalculate the hash value of the window
		if (i < txt_len - pat_len)
		{
			txt_hash = (n_chars * (txt_hash - bible[i] * hash_factor) + bible[i + pat_len]) % prime;
			if (txt_hash < 0)
				txt_hash = txt_hash + prime;
		}
	}
	return (n_appear);
}
