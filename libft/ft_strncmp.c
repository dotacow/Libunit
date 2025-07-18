/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:33:39 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/01 20:24:33 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s2 || !s2)
	{
		ft_putendl_fd("strncmp err, no s1 or no s2", 2);
		exit(1);
	}
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
