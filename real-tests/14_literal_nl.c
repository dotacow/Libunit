/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_literal_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:23:03 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 18:42:00 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	literal_nl(void)
{
	int		fd;
	char	*line;

	fd = open("txtfiles/literal_nl.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!ft_strncmp("hello world \\n", line, 14))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
