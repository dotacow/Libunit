/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:09:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 17:11:29 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/include/libft.h"

//thing to test:
char *get_next_line(int fd);
int gnl_launcher(void);
//actual tests:
int alternating_lines(void);
int alternating_nl(void);
int no_newline(void);
int no_newline_at_end(void);
int newline_at_start(void);
int single_character(void);
int big_file(void);
int big_single_line(void);
int buffer_size_less_one(void);
int buffer_size_0(void);
int buffer_size_1(void);
int buffer_size_negative(void);
int buffer_size_large(void);
int header_protection(void);
int empty_file(void);
int single_character_nl(void);
int big_file(void);
int buffer_size_less_zero(void);
int	buffer_size_zero(void);
int	buffer_size_one(void);
#endif
