/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:41:34 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/04 23:20:06 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Prints array and returns the number of elements that would've been
//written, returns 0 in case of error with an error message
int	ft_printarr(char **arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!arr || *arr == NULL)
	{
		ft_putendl_fd("Printarr: Array doesn't exist\n", 2);
		return (0);
	}
	while (arr[i])
	{
		count += ft_strlen(arr[i]);
		ft_putendl_fd(arr[i], 1);
		i++;
	}
	return (count);
}
