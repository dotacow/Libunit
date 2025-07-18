/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:36:46 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/01 20:26:27 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	if (!s)
	{
		ft_putendl_fd("(strrchr error, no string)", 2);
		exit(1);
	}
	ch = c;
	i = ft_strlen(s);
	if (!ch)
		return ((char *)(s) + i);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)(s) + i);
		i--;
	}
	if (s[0] == ch)
		return ((char *)(s) + i);
	return (0);
}
