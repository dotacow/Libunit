/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_buffer_size_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:30:00 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/19 16:43:14 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 0
#include "tests.h"

int	buffer_size_zero(void)
{
	int		fd;
	char	*line;

	fd = open("real-test/txtfiles/txtfiles/buffer_size_zero.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	close(fd);
	if (line)
	{
		free(line);
		return (1);
	}
	return (0);
}
