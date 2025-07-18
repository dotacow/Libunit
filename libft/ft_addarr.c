/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:27:08 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/05 23:34:31 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**arr_cpy(char *str, char **old_arr)
{
	int		i;
	int		size;
	char	**arr;

	i = 0;
	size = ft_arrlen(old_arr);
	arr = malloc(sizeof(char *) * (size + 2));
	if (!arr)
		return (NULL);
	while (old_arr[i] != NULL)
	{
		arr[i] = ft_strdup(old_arr[i]);
		i++;
	}
	arr[size] = ft_strdup(str);
	arr[size + 1] = NULL;
	return (arr);
}

//adds string(str) to arr(old_arr) as its last element before NULL terminating it
//returns NULL in case of empty str or empty arr (old_arr) with error msg
//MUST SEND NULL TERMINATED ARRAY!!!!
//Frees Original arr, need to reuse same arr
char	**ft_addarr(char *str, char **old_arr)
{
	char	**new_arr;

	if (!str)
	{
		ft_putendl_fd("addarr error, no str present, nothing to add", 2);
		return (NULL);
	}
	if (!old_arr || *old_arr == NULL)
	{
		ft_putendl_fd("addarr error, no arr present, nothing to edit", 2);
		return (NULL);
	}
	new_arr = arr_cpy(str, old_arr);
	if (!new_arr)
	{
		ft_putendl_fd("Malloc error in new arr", 2);
		return (NULL);
	}
	ft_farray(old_arr);
	return (new_arr);
}
