/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:03:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 16:01:14 by yokitane         ###   ########.fr       */
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
	tests->silent = 0;
	load_test(tests, "empty_file", &empty_file,0);
	load_test(tests, "empty_file", &empty_file,0);
	load_test(tests, "empty_file", &empty_file,1);
	ret = launch_tests(tests,"tester");
	delete_list(tests);
	return (ret);
}