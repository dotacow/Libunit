/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:13:52 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/04 22:16:32 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//calculates size of array, returns size of arr on success, 0 on NULL arr
//ARRAY MUST BE NULL TERMINATED!!!!!!!!
size_t	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	if (!arr || *arr == NULL)
		return (0);
	while (arr[len] != NULL)
		len++;
	return (len);
}
