/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_big_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:44:07 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/19 18:11:37 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	big_file(void)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open("txtfiles/big_file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		size += ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (size != 100339)
		return (1);
	return (0);
}
