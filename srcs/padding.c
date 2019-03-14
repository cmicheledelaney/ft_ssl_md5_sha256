/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:57:01 by ccodiga           #+#    #+#             */
/*   Updated: 2019/03/14 08:50:25 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	ft_strlen_uint64(const char *s)
{
	uint64_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	get_chunks(char *message, uint32_t **words, uint64_t *char_nbr)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		(*words)[i] = (uint32_t)(uint8_t)message[*char_nbr + 3] |
					((uint32_t)(uint8_t)message[*char_nbr + 2] << 8) |
					((uint32_t)(uint8_t)message[*char_nbr + 1] << 16) |
					((uint32_t)(uint8_t)message[*char_nbr] << 24);
		*char_nbr += 4;
	}
}

/*
** For the padding a one-bit one will be added directly after the message, which
** results in being a added 1, leftshifted 7 times, so that it results in the
** value 128, 0x80 in hex respectively. The expression "Hello World! results
** in the values 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33, which
** results in the binary:
** 0100 1000 0110 0101 0110 1100 0110 1100 0110 1111 0010 0000 0101 0111 0110
** 1111 0111 0010 0110 1100 0110 0100 0010 0001
** after the added one-bit and the padding with the zeroes, it looks like this:
** 0100 1000 0110 0101 0110 1100 0110 1100 0110 1111 0010 0000 0101 0111 0110
** 1111 0111 0010 0110 1100 0110 0100 0010 0001 1000 0000 0000 0000 0000 0000
** 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 ...
** until we reach the 448th bit, then we have to add the size as an uint64_t.
*/

void	add_size_sha(char *message, uint64_t size)
{
	message[7] = size;
	message[6] = size >> 8;
	message[5] = size >> 16;
	message[4] = size >> 24;
	message[3] = size >> 32;
	message[2] = size >> 40;
	message[1] = size >> 48;
	message[0] = size >> 56;
}

int		padding(char **message, int little_endian)
{
	int			added_memory;
	uint64_t	orig_len;
	uint64_t	*uint64_ptr;
	uint64_t	total_size;

	orig_len = ft_strlen_uint64(*message);
	if ((orig_len * 8) % 512 > 440)
		added_memory = (512 - ((orig_len * 8) % 512)) + 512;
	else
		added_memory = 512 - ((orig_len * 8) % 512);
	(*message)[orig_len] = 0x80;
	(*message)[orig_len + 1] = '\0';
	uint64_ptr = (uint64_t *)(*message);
	if (!(*message = (char *)ft_memalloc((orig_len + (added_memory / 8)))))
		exit(-1);
	*message = ft_strcat(*message, (char *)uint64_ptr);
	free(uint64_ptr);
	uint64_ptr = (uint64_t *)(*message);
	total_size = orig_len + (added_memory / 8);
	if (little_endian == 1)
		uint64_ptr[(total_size / 8) - 1] = (orig_len * 8);
	else
		add_size_sha(&(*message)[total_size - 8], (orig_len * 8));
	return (total_size);
}
