/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:35:52 by ccodiga           #+#    #+#             */
/*   Updated: 2019/03/14 08:45:27 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		p_option(char **argv, int *i, int *j, int *q_r)
{
	char	*message;

	message = read_stdinput();
	ft_printf("%s", message);
	g_commands[(int)argv[1][0]](&message);
	ft_printf("\n");
	i += 0;
	j += 0;
	q_r += 0;
	free(message);
	return (0);
}

int		s_option(char **argv, int *i, int *j, int *q_r)
{
	char *message;

	message = ft_strnew(1);
	if ((argv[*i][*j] == 's') && (argv[*i][*j + 1] == '\0')
			&& (argv[*i + 1] == NULL))
	{
		ft_printf("%s: option requires an argument -- s\nusage: ", argv[1]);
		ft_printf("%s [-pqr] [-s string] [files ...]\n", argv[1]);
		exit(-1);
	}
	else if (argv[*i][*j] == 's' && argv[*i][*j + 1] == '\0')
		message = hold_and_free(message, argv[++(*i)]);
	else if (argv[*i][*j] == 's')
		message = hold_and_free(message, (&argv[*i][++(*j)]));
	while (argv[*i][*j])
		(*j)++;
	(*j)--;
	if (q_r[1] == 0 && q_r[0] == 0)
		ft_printf("%s (\"%s\") = ", argv[1], message);
	g_commands[(int)argv[1][0]](&message);
	message[ft_strlen(message) - 1] = '\0';
	(q_r[1] == 1 && q_r[0] == 0) ? (ft_printf(" \"%s\"", message)) : (0);
	ft_printf("\n");
	free(message);
	return (0);
}
