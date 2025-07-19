/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_alternating_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:13:27 by salshaha          #+#    #+#             */
/*   Updated: 2025/07/19 16:35:53 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tests.h"

static int	check_line_lengths(int fd, int first_len)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len != first_len)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	alternating_lines(void)
{
	int		fd;
	char	*line;
	int		result;
    int     first_len;

	fd = open("txtfiles/alternating.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
    {
        close(fd);
		return (0);
    }
    first_len = ft_strlen(line);
	result = check_line_lengths(fd, first_len);
	free(line);
	close(fd);
	return (result);
}
