/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:46:19 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/04 16:47:21 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ssl.h"

uint32_t	rightrotate(uint32_t num, unsigned int rotation)
{
	rotation %= 31;
	while (rotation--)
	{
		num = (((num >> 1) & (~(1 << 31))) | ((num & 1) << 31));
	}
	return (num);
}

uint32_t	rightshift(uint32_t nbr, int i)
{
	return (nbr >> i);
}

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}
