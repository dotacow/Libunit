/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_single_character_nl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:35:10 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/19 18:11:26 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	single_character_nl(void)
{
	int		fd;
	char	*line;

	fd = open("txtfiles/single_character_nl.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line || line[1] != '\n')
	{
		close(fd);
		return (1);
	}
	free(line);
	line = get_next_line(fd);
	if (line)
	{
		free(line);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
