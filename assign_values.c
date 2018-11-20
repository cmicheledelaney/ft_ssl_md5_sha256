/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:49:31 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/04 16:57:09 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ssl.h"
#include "init_values.h"

void	init_a_b_c_d(uint32_t **a_b_c_d)
{
	(*a_b_c_d)[0] = g_a;
	(*a_b_c_d)[1] = g_b;
	(*a_b_c_d)[2] = g_c;
	(*a_b_c_d)[3] = g_d;
}

void	assign_cap_var(uint32_t **cap_var, uint32_t *a_b_c_d)
{
	(*cap_var)[0] = a_b_c_d[0];
	(*cap_var)[1] = a_b_c_d[1];
	(*cap_var)[2] = a_b_c_d[2];
	(*cap_var)[3] = a_b_c_d[3];
}

void	init_digest(uint32_t **digest)
{
	(*digest)[0] = g_h0_sha;
	(*digest)[1] = g_h1_sha;
	(*digest)[2] = g_h2_sha;
	(*digest)[3] = g_h3_sha;
	(*digest)[4] = g_h4_sha;
	(*digest)[5] = g_h5_sha;
	(*digest)[6] = g_h6_sha;
	(*digest)[7] = g_h7_sha;
}

void	update_abcdefgh(uint32_t **abcdefgh, uint32_t *temp)
{
	(*abcdefgh)[7] = (*abcdefgh)[6];
	(*abcdefgh)[6] = (*abcdefgh)[5];
	(*abcdefgh)[5] = (*abcdefgh)[4];
	(*abcdefgh)[4] = (*abcdefgh)[3] + temp[0];
	(*abcdefgh)[3] = (*abcdefgh)[2];
	(*abcdefgh)[2] = (*abcdefgh)[1];
	(*abcdefgh)[1] = (*abcdefgh)[0];
	(*abcdefgh)[0] = temp[0] + temp[1];
}

void	assign_abcdefgh(uint32_t **abcdefgh, uint32_t **digest)
{
	(*abcdefgh)[0] = (*digest)[0];
	(*abcdefgh)[1] = (*digest)[1];
	(*abcdefgh)[2] = (*digest)[2];
	(*abcdefgh)[3] = (*digest)[3];
	(*abcdefgh)[4] = (*digest)[4];
	(*abcdefgh)[5] = (*digest)[5];
	(*abcdefgh)[6] = (*digest)[6];
	(*abcdefgh)[7] = (*digest)[7];
}
