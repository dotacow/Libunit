/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_srch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:27:15 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/08 15:58:15 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//searches the array, and returns the number of times str is repeated in it
//returns (-1) on error
//MUST SEND NULL TERMINATED ARRAY!!!!!
int	ft_arr_srch(char *str, char **arr)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (!str || !arr)
		return (-1);
	size = ft_arrlen(arr);
	while (i < size)
	{
		if (ft_strncmp(arr[i], str, ft_strlen(str)) == 0)
			break;
		i++;
	}
	if (arr[i] == NULL)
		return (0);
	else
		return (i);
}
