/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_alternating_nl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:26:04 by salshaha          #+#    #+#             */
/*   Updated: 2025/07/19 17:25:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	alternating_nl(void)
{
	int		fd;
	char	*line;
	int		new_line;

	new_line = 0;
	fd = open("txtfiles/alternating_newlines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			new_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (new_line > 1)
		return (0);
	return (1);
}
