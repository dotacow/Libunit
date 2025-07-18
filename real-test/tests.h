/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:09:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/18 17:24:29 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//thing to test:
char *get_next_line(int fd);
int gnl_launcher(void);
//actual tests:
int empty_file(void);
int no_newline(void);
int no_newline_at_end(void);
int no_newline_at_start(void);
int single_character(void);
int multiple_characters(void);
int big_file(void);
int big_single_line(void);
int buffer_size_0(void);
int buffer_size_1(void);
int buffer_size_negative(void);
int buffer_size_large(void);
#endif