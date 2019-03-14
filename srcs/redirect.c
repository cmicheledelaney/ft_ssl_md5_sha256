/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:11 by ccodiga           #+#    #+#             */
/*   Updated: 2019/03/14 08:45:40 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	go_to_stdinput(char **argv, char *message, int *q_r)
{
	if (q_r[0] == 1 || q_r[1] == 1 || !argv[2])
	{
		message = read_stdinput();
		g_commands[(int)argv[1][0]](&message);
		ft_printf("\n");
		ft_memset(message, '\0', ft_strlen(message));
		free(message);
	}
}

void	solve_print(char **argv, char **message, int *q_r, int i)
{
	if (q_r[1] == 0 && q_r[0] == 0)
		ft_printf("%s (%s) = ", argv[1], argv[i]);
	g_commands[(int)argv[1][0]](message);
	if (q_r[1] != 1 && q_r[0] != 1)
		ft_printf("\n");
	if (q_r[1] == 1 && q_r[0] == 0)
		ft_printf(" ");
	ft_memset(*message, '\0', ft_strlen(*message));
	if (q_r[1] == 1 && q_r[0] == 0)
		ft_printf("%s\n", argv[i]);
	if (q_r[0] == 1)
		ft_printf("\n");
}

int		option_handler(char **argv, int *i, int *j, int *q_r)
{
	if (argv[*i][*j] == 's' || argv[*i][*j] == 'p')
		g_options[(int)(argv[*i][*j])](argv, i, j, q_r);
	if (argv[*i] == NULL)
		return (0);
	(argv[*i][*j] == 'r') ? (q_r[1] = 1) : (0);
	(argv[*i][*j] == 'q') ? (q_r[0] = 1) : (0);
	return (1);
}
