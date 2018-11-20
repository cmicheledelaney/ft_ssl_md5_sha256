/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:19:26 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/11 11:22:35 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SSL_H
# define _FT_SSL_H

# include <stdint.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# define IS_OPT(x) (x == 'q' || x == 's' || x == 'r' || x == 'p')

int			error_usage(int argc, char **argv);
int			parsing(char **argv);
int			parse_files(char **argv, int i, int *q_r);
int			p_option(char **argv, int *i, int *j, int *q_r);
int			s_option(char **argv, int *i, int *j, int *q_r);
void		f_md5(char **message);
void		f_sha256(char **message);
void		init_a_b_c_d(uint32_t **a_b_c_d);
void		assign_cap_var(uint32_t **cap_var, uint32_t *a_b_c_d);
void		init_digest(uint32_t **digest);
void		update_abcdefgh(uint32_t **abcdefgh, uint32_t *temp);
void		assign_abcdefgh(uint32_t **abcdefgh, uint32_t **digest);
uint32_t	rightrotate(uint32_t num, unsigned int rotation);
uint32_t	rightshift(uint32_t nbr, int i);
uint32_t	leftrotate(uint32_t x, uint32_t c);
int			option_handler(char **argv, int *i, int *j, int *q_r);
char		*hold_and_free(char *old, char *addition);
void		add_size(char **message, uint64_t size, int little_endian);
void		print_digest(uint8_t **digest, int little_endian, int size);
int			padding(char **message, int little_endian);
void		little_endian_digest(uint8_t **digest, uint32_t *a_b_c_d);
void		big_endian_digest(uint8_t **digest, uint32_t a_b_c_d_e_f_g_h[8]);
void		get_chunks(char *message, uint32_t **words, uint64_t *char_nbr);
char		*read_stdinput(void);
int			read_file(char **message, char **argv, int i, int *q_r);
void		go_to_stdinput(char **argv, char *message, int *q_r);
int			print_error(char **argv, int i, int j);
void		solve_print(char **argv, char **message, int *q_r, int i);

typedef int		(*t_function_ptr_opt)(char **argv, int *i, int *j,
				int *q_r);
typedef void	(*t_function_ptr_cmd)(char **message);

t_function_ptr_opt g_options[123];
t_function_ptr_cmd g_commands[123];

#endif
