/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_buffer_size_less_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:15:40 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/19 17:10:38 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE -1
#include "tests.h"

int	buffer_size_less_zero(void)
{
	int		fd;
	char	*line;

	fd = open("txtfiles/buffer_size_less_zero.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (line != NULL)
	{
		free(line);
		close(fd);
		return (1);
	}
	return (0);
}
