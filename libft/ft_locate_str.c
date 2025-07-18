/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:13:12 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/08 16:20:58 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locates the string starting with "str" in the array
//and returns a pointer to the entire string that's in the array
//returns NULL in case of empty str, arr or str not found
//MUST PROVIDE NULL TERMINATED ARRAY!!!!
char	*ft_locate_str(char *str, char **arr)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!arr || !str)
		return (NULL);
	size = ft_arrlen(arr);
	while (i < size)
	{
		if (ft_strnstr(arr[i], str, ft_strlen(str)))
			break;
		i++;
	}
	if (arr[i] == NULL)
		return (NULL);
	else
		return (arr[i]);
}
