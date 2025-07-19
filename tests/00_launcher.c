/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:03:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:49 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "tests.h"

int	test_launcher(void)
{
	t_unit_test	*tests;
	int			ret;

	tests = malloc(sizeof(t_unit_test));
	if (!tests)
		return (1);
	tests->next = NULL;
	tests->silent = 0;
	load_test(tests, "ok_test", ok_test, 0);
	load_test(tests, "ko_test", ko_test, 1);
	load_test(tests, "signal_test", signal_test, 1);
	ret = launch_tests(tests, "tester");
	delete_list(tests);
	return (ret);
}
