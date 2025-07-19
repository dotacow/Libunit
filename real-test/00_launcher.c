/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:03:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 16:59:47 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../framework/libunit.h"

int gnl_launcher(void)
{
	t_unit_test	*tests;
	int			ret;

	tests = malloc(sizeof(t_unit_test));
	if (!tests)
		return (1);
	tests->next = NULL;
	load_test(tests, "single_character", &single_character_nl);
	load_test(tests, "big_file", &big_file);
	load_test(tests, "buffer_size_less_zero", &buffer_size_less_zero);
	ret = launch_tests(tests,"tester");
	delete_list(tests);
	return (ret);
}
