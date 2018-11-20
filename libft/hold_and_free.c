/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:39:57 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/07 12:40:16 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*hold_and_free(char *old, char *addition)
{
	char *message;

	message = ft_strjoin(old, addition);
	free(old);
	return (message);
}
