/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_newline_at_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:23:07 by salshaha          #+#    #+#             */
/*   Updated: 2025/07/19 16:37:11 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	first_line_is_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	if (line[0] == '\n')
    {
        free(line);
		return (0);
    }
    free(line);
	return (1);
}

int	newline_at_start(void)
{
	int		fd;
	int		result;

	fd = open("txtfiles/newline_at_start.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	result = first_line_is_newline(fd);
	close(fd);
	return (result);
}
