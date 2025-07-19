/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:09:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 18:16:11 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

//thing to test:
char	*get_next_line(int fd);
int		gnl_launcher(void);
//actual tests:
int		empty_file(void); //00
int		alternating_lines(void);//01
int		alternating_nl(void);			//02
int		no_newline(void);//03
int		only_newline(void);//04
int		newline_at_start(void);//05
int		single_character_nl(void);//06
int		big_file(void);//07
int		single_character(void);//08
int		invalid_file(void);//09
int		invalid_perms(void);//10
int		long_line_no_nl(void);//11
int		long_line_nl(void);//12
int		only_whitespaces(void);//13
int		literal_nl(void);//14

#endif