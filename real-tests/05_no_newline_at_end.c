/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_no_newline_at_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salshaha <salshaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:09:56 by salshaha          #+#    #+#             */
/*   Updated: 2025/07/19 12:10:55 by salshaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	check_last_line_newline(int fd)
{
	char	*line;
	char	*last;
	
	last = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (last)
			free(last);
		last = line;
		line = get_next_line(fd);
	}
	if (!last)
		return (1);
	if (last[ft_strlen(last) - 1] != '\n')
    {
        free(last);
		return (1);
    }
    free(last);
	return (0);
}

int	no_newline_at_end(void)
{
	int		fd;
	int		result;

	fd = open("txtfiles/no_newline_at_end.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	result = check_last_line_newline(fd);
	close(fd);
	return (result);
}
