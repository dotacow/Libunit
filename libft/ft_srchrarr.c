/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchrarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:03:03 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/07 15:27:34 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//searchs the array for the string with fnd, if found, and if
//rplc is not null, replaces fnd with rplc in the array
//and returns the array.
//returns null if no array, returns array if no fnd or rplc exist
//MUST SEND NULL TERMINATED ARRAY
//OLD_ARR WILL BE FREED AT SUCCESS
char	**ft_srchrarr(char *fnd, char **old_arr, char *rplc)
{
	char	**new_arr;
	int		i;

	i = -1;
	if (!old_arr || *old_arr == NULL)
		return (NULL);
	if (!fnd || !rplc)
		return (old_arr);
	while (old_arr[++i] != NULL)
	{
		if (ft_strnstr(old_arr[i], fnd, ft_strlen(fnd)) != NULL)
			break;
	}
	if (old_arr[i] == NULL)
		return (old_arr);
	free(old_arr[i]);
	old_arr[i] = ft_strdup(rplc);
	new_arr = ft_cpyarr(old_arr);
	if (!new_arr)
		return (NULL);
	ft_farray(old_arr);
	return (new_arr);
}
