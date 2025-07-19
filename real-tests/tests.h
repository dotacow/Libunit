/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:09:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 17:07:28 by yokitane         ###   ########.fr       */
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
int		empty_file(void);
int		alternating_lines(void);
int		alternating_nl(void);
int		no_newline(void);
int		only_newline(void);
int		newline_at_start(void);
#endif