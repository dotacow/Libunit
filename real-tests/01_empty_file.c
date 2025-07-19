/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_empty_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:52:45 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 17:08:35 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	empty_file(void)
{
	int		fd;
	char	*line;

	fd = open("txtfiles/empty.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line != NULL)
	{
		free(line);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
