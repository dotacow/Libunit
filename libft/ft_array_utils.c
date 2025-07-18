/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:37:27 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/05 14:29:08 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//edits the array and returns an edited array in case of edit modes or
//same array in case of print actions, don't take the return val if printing
//return Null in case of errors, including wrong input
//c: copy, p: print, ap: addprint, +: add string, -: remove string
char	**edit_arr(char *str, char **arr, char mode)
{
	(void) str;
	if (mode == 'c')
		return (ft_cpyarr(arr));
	else if (mode == 'p')
		ft_printarr(arr);
	else if (mode == 'ap')
		ft_addprintarr(str, arr);
	else if (mode == '+')
		return (ft_addarr(str, arr));
	else if (mode == '-')
		return (ft_subarr(str, arr));
	else
		return (NULL);
	return (arr);
}
