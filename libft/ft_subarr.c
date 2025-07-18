/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:30:10 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/06 17:19:05 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**rm_arr(char *str, char **old_arr)
{
	int		i;
	int		j;
	int		size;
	char	**new_arr;

	i = 0;
	j = 0;
	size = ft_arrlen(old_arr);
	new_arr = malloc(sizeof(char *) * size);
	if (!new_arr)
		return (NULL);
	while (old_arr[i] != NULL)
	{
		if (ft_strnstr(old_arr[i], str, ft_strlen(str) + 1) == NULL)
		{
			new_arr[j] = ft_strdup(old_arr[i]);
			j++;
		}
		i++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

//Subtracts string (str) from array (old_arr) and returns the array (new_arr)
//returns the array (old_arr) in case of empty str or str not found
//returns NULL with error msg in case of empty/wrong array
//ONLY ACCEPTS NULL TERMINATED ARRAYS!!!
//Frees old_arr after use, must assign to same arr
char	**ft_subarr(char *str, char **old_arr)
{
	int		i;
	char	**new_arr;

	i = -1;
	if (!old_arr || *old_arr == NULL)
	{
		ft_putendl_fd("subarr error, no array to subtract from", 2);
		return (NULL);
	}
	if (!str)
		return (old_arr);
	while (old_arr[++i] != NULL)
	{
		if (ft_strnstr(old_arr[i], str, ft_strlen(str)))
			break;
	}
	if (old_arr[i] == NULL)
		return (old_arr);
	new_arr = rm_arr(str, old_arr);
	if (!new_arr)
		return (NULL);
	ft_farray(old_arr);
	return (new_arr);
}
