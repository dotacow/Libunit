/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addprintarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:43:27 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/04 17:04:12 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Prints string then prints the array and returns
//the number of elements that would've been written
//returns 0 in case of error with an error message
int	ft_addprintarr(char *print, char **arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!arr || *arr == NULL)
	{
		ft_putendl_fd("Addrintarr: Array doesn't exit", 2);
		return (0);
	}
	if (!print)
	{
		ft_putendl_fd("Nothing to print before arr", 2);
		return (0);
	}
	while (arr[i])
	{
		count += ft_strlen(arr[i]);
		count += ft_strlen(print) + 1;
		ft_putstr_fd(print, 1);
		ft_putendl_fd(arr[i], 1);
		i++;
	}
	return (count);
}
