/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_long_line_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:51:35 by salshaha          #+#    #+#             */
/*   Updated: 2025/07/19 18:38:08 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	check_for_newline(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (i != 10)
		return (1);
	return (0);
}

int	long_line_nl(void)
{
	int	fd;
	int	result;

	fd = open("txtfiles/long_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	result = check_for_newline(fd);
	close(fd);
	return (result);
}
