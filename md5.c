/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:54:43 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/11 12:15:39 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ssl.h"
#include "numbers_md5.h"

void	helper(uint32_t **cap, uint32_t *g, uint32_t *f, int i)
{
	*f = 0;
	*g = 0;
	if (i < 16)
	{
		*f = ((*cap)[1] & (*cap)[2]) | ((~(*cap)[1]) & (*cap)[3]);
		*g = i;
	}
	else if (16 <= i && i < 32)
	{
		*f = ((*cap)[3] & (*cap)[1]) | ((~(*cap)[3]) & (*cap)[2]);
		*g = (5 * i + 1) % 16;
	}
	else if (32 <= i && i < 48)
	{
		*f = ((*cap)[1] ^ (*cap)[2] ^ (*cap)[3]);
		*g = (3 * i + 5) % 16;
	}
	else if (48 <= i && i < 64)
	{
		*f = ((*cap)[2] ^ ((*cap)[1] | (~(*cap)[3])));
		*g = (7 * i) % 16;
	}
}

void	hashing_md5(uint32_t *words, uint32_t *cap_var,
			uint32_t **a_b_c_d)
{
	int			i;
	uint32_t	g;
	uint32_t	f;

	i = -1;
	assign_cap_var(&cap_var, *a_b_c_d);
	while (++i < 64)
	{
		helper(&cap_var, &g, &f, i);
		f = f + cap_var[0] + g_k[i] + words[g];
		cap_var[0] = cap_var[3];
		cap_var[3] = cap_var[2];
		cap_var[2] = cap_var[1];
		cap_var[1] = cap_var[1] + leftrotate(f, g_s[i]);
	}
	(*a_b_c_d)[0] = (*a_b_c_d)[0] + cap_var[0];
	(*a_b_c_d)[1] = (*a_b_c_d)[1] + cap_var[1];
	(*a_b_c_d)[2] = (*a_b_c_d)[2] + cap_var[2];
	(*a_b_c_d)[3] = (*a_b_c_d)[3] + cap_var[3];
}

void	swap_bytes(uint32_t **abcd)
{
	int			i;

	i = -1;
	while (++i < 4)
		(*abcd)[i] = (((*abcd)[i] >> 24) & 0xff) |
					(((*abcd)[i] << 8) & 0xff0000) |
				(((*abcd)[i] >> 8) & 0xff00) |
				(((*abcd)[i] << 24) & 0xff000000);
}

void	algorithm(char *message, int nbr_chunks)
{
	uint32_t	*words;
	uint32_t	*cap_var;
	uint32_t	*a_b_c_d;
	uint8_t		*digest;
	int			i;

	a_b_c_d = (uint32_t *)ft_memalloc(sizeof(uint32_t) * 5);
	digest = (uint8_t *)ft_memalloc(sizeof(uint8_t) * 17);
	cap_var = (uint32_t *)ft_memalloc(sizeof(uint32_t) * 5);
	init_a_b_c_d(&a_b_c_d);
	i = nbr_chunks;
	while ((nbr_chunks) > 0)
	{
		words = (uint32_t *)&message[(i - nbr_chunks) * 64];
		hashing_md5(words, cap_var, &a_b_c_d);
		nbr_chunks--;
	}
	swap_bytes(&a_b_c_d);
	i = -1;
	while (++i < 4)
		(cnt_digits(a_b_c_d[i], "0123456789abcdef") < 8) ?
		(ft_printf("0") && ft_printf("%x", a_b_c_d[i])) :
		(ft_printf("%x", a_b_c_d[i]));
	free(a_b_c_d);
	free(cap_var);
	free(digest);
}

void	f_md5(char **message)
{
	int	len;
	int	nbr_chunks;

	len = padding(message, 1);
	nbr_chunks = (len / 64);
	algorithm(*message, nbr_chunks);
}
