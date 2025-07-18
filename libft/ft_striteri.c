/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:10:10 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/01 20:21:24 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putendl_fd("(striteri error, no str)", 2);
		return ;
	}
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
