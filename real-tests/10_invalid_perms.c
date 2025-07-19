/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_invalid_perms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:07:56 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 18:37:53 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	invalid_perms(void)
{
	char	*line;
	int		fd;

	fd = open("txtfiles/invalid_perms.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
