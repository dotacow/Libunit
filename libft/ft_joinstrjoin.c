/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:37:22 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/01 21:00:47 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinstrjoin(char *left, char *middle, char *right)
{
	char	*joined;

	if (!left)
		ft_putendl_fd("str1 doesn't exit\n", 2);
	if (!middle)
		ft_putendl_fd("str2 doesn't exist\n", 2);
	if (!right)
		ft_putendl_fd("str3 doesn't exit\n", 2);
	if (!left || !middle || !right)
		return (NULL);
	joined = ft_strjoin(middle, right);
	if (!joined)
	{
		ft_putendl_fd("join-strjoin err\n", 2);
		return (NULL);
	}
	left = ft_strjoin(left, joined);
	if (!left)
	{
		ft_putendl_fd("joinstrjoin err\n", 2);
		return (NULL);
	}
	free(joined);
	return (left);
}
