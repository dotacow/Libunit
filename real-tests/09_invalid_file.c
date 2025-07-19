/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_invalid_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:07:56 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 18:28:05 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	invalid_file(void)
{
	char	*line;
	int		fd;

	fd = open("txtfiles/asdasd.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		return (1);
	}
	return (0);
}
