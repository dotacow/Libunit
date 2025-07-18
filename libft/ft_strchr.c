/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:21:05 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/06 16:57:15 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	if (!s)
	{
		ft_putendl_fd("(strchr err, no str)", 2);
		return (NULL);
	}
	ch = c;
	i = ft_strlen(s);
	if (ch == '\0')
		return ((char *)(s) + i);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)(s) + i);
		i++;
	}
	return (NULL);
}
