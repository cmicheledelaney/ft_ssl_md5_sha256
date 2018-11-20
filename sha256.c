/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:03 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/11 11:58:36 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ssl.h"
#include "numbers_sha.h"

void	compression_function(uint32_t **abcdefgh, uint32_t **words,
		uint32_t *s)
{
	int			i;
	uint32_t	ch;
	uint32_t	maj;
	uint32_t	temp[2];

	i = -1;
	while (++i < 64)
	{
		s[1] = (rightrotate((*abcdefgh)[4], 6)) ^ (rightrotate(
					(*abcdefgh)[4], 11)) ^ (rightrotate((*abcdefgh)[4], 25));
		ch = ((*abcdefgh)[4] & (*abcdefgh)[5]) ^ (~(*abcdefgh)[4] &
				(*abcdefgh)[6]);
		temp[0] = (*abcdefgh)[7] + s[1] + ch + g_k_sha[i] + (*words)[i];
		s[0] = (rightrotate((*abcdefgh)[0], 2)) ^ (rightrotate(
					(*abcdefgh)[0], 13)) ^ (rightrotate((*abcdefgh)[0], 22));
		maj = ((*abcdefgh)[0] & (*abcdefgh)[1]) ^ ((*abcdefgh)[0] &
				(*abcdefgh)[2]) ^ ((*abcdefgh)[1] & (*abcdefgh)[2]);
		temp[1] = s[0] + maj;
		update_abcdefgh(abcdefgh, temp);
	}
}

void	hashing_sha(uint32_t **abcdefgh, uint32_t **digest,
		uint32_t **words)
{
	int			i;
	uint32_t	s[2];

	i = 15;
	while (++i <= 63)
	{
		s[0] = (rightrotate((*words)[i - 15], 7)) ^
				(rightrotate((*words)[i - 15], 18)) ^
				(rightshift((*words)[i - 15], 3));
		s[1] = (rightrotate((*words)[i - 2], 17)) ^
				(rightrotate((*words)[i - 2], 19)) ^
				(rightshift((*words)[i - 2], 10));
		(*words)[i] = (*words)[i - 16] + s[0] +
							(*words)[i - 7] + s[1];
	}
	assign_abcdefgh(abcdefgh, digest);
	compression_function(abcdefgh, words, s);
	i = -1;
	while (++i < 8)
		(*digest)[i] = (*digest)[i] + (*abcdefgh)[i];
}

void	algorithm_sha(char *message, int nbr_chunks)
{
	uint32_t	*words;
	uint64_t	i;
	uint32_t	*digest;
	uint32_t	*abcdefgh;

	digest = ft_memalloc(sizeof(uint32_t) * 9);
	abcdefgh = ft_memalloc(sizeof(uint32_t) * 9);
	words = ft_memalloc(sizeof(uint32_t) * 65);
	init_digest(&digest);
	i = 0;
	while ((nbr_chunks) > 0)
	{
		get_chunks(message, &words, &i);
		hashing_sha(&abcdefgh, &digest, &words);
		nbr_chunks--;
	}
	i = -1;
	while (++i < 8)
		(cnt_digits(digest[i], "0123456789abcdef") < 8) ?
		(ft_printf("0") && ft_printf("%x", digest[i])) :
		(ft_printf("%x", digest[i]));
	free(words);
	free(digest);
	free(abcdefgh);
}

void	f_sha256(char **message)
{
	int len;
	int nbr_chunks;

	len = padding(message, 0);
	nbr_chunks = (len / 64);
	algorithm_sha(*message, nbr_chunks);
}
