/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:55:54 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/11 11:35:37 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INIT_VALUES_H
# define _INIT_VALUES_H

# include "ft_ssl.h"

uint32_t g_a = 0x67452301;
uint32_t g_b = 0xefcdab89;
uint32_t g_c = 0x98badcfe;
uint32_t g_d = 0x10325476;

uint32_t g_h0_sha = 0x6a09e667;
uint32_t g_h1_sha = 0xbb67ae85;
uint32_t g_h2_sha = 0x3c6ef372;
uint32_t g_h3_sha = 0xa54ff53a;
uint32_t g_h4_sha = 0x510e527f;
uint32_t g_h5_sha = 0x9b05688c;
uint32_t g_h6_sha = 0x1f83d9ab;
uint32_t g_h7_sha = 0x5be0cd19;

#endif
