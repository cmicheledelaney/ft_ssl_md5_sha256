/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:48:47 by ccodiga           #+#    #+#             */
/*   Updated: 2019/03/14 08:45:08 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		error_usage(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		exit(-1);
	}
	if (ft_strcmp(argv[1], "md5") != 0 && ft_strcmp(argv[1], "sha256") != 0)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv[1]);
		ft_printf("Standard commands:\n\nMessage Digest commands:\nmd5\nsha256");
		ft_printf("\n\nCipher commands:\n");
		exit(-1);
	}
	return (0);
}

int		print_error(char **argv, int i, int j)
{
	ft_printf("%s: illegal option -- %c\n", argv[1], argv[i][j]);
	ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
	exit(-1);
}

char	*read_stdinput(void)
{
	char	*message;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	message = ft_strnew(1);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		message = hold_and_free(message, buff);
	}
	return (message);
}

char	*hold_and_free(char *old, char *addition)
{
	char *message;

	message = ft_strjoin(old, addition);
	free(old);
	return (message);
}
