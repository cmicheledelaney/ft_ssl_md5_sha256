/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:18:50 by ccodiga           #+#    #+#             */
/*   Updated: 2019/03/14 08:45:15 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_function_pointer(void)
{
	g_options['p'] = p_option;
	g_options['s'] = s_option;
	g_commands['m'] = f_md5;
	g_commands['s'] = f_sha256;
}

int		main(int argc, char **argv)
{
	init_function_pointer();
	argv[argc] = NULL;
	error_usage(argc, argv);
	parsing(argv);
}

int		parsing(char **argv)
{
	int		i;
	int		j;
	int		q_r[2];
	char	*message;

	i = 1;
	q_r[0] = 0;
	q_r[1] = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			(argv[i][j] == '-') ? (j++) : (0);
			if (argv[i][0] == '-' && (IS_OPT(argv[i][j])))
				option_handler(argv, &i, &j, q_r);
			else if ((argv[i][0] == '-') && (argv[i][1] != '-'))
				return (print_error(argv, i, j));
			else
				return (parse_files(argv, i - 1, q_r));
		}
	}
	go_to_stdinput(argv, message = NULL, q_r);
	return (0);
}

int		parse_files(char **argv, int i, int *q_r)
{
	int		fd;
	char	*message;

	message = ft_strnew(1);
	while (argv[++i])
	{
		fd = read_file(&message, argv, i, q_r);
		if (fd < 0)
		{
			ft_printf("%s: ", argv[1]);
			perror(argv[i]);
		}
		close(fd);
	}
	free(message);
	return (0);
}

int		read_file(char **message, char **argv, int i, int *q_r)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		fd;

	if ((fd = open(argv[i], O_RDONLY)) >= 0)
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			*message = hold_and_free(*message, buff);
		}
		solve_print(argv, message, q_r, i);
	}
	return (fd);
}
