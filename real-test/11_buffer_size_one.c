/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_buffer_size_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:31:00 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/19 16:43:01 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1
#include "tests.h"

int	buffer_size_one(void)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open("real-test/txtfiles/buffer_size_one.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
		if (line_count > 250)
		{
			if (line)
				free(line);
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}
