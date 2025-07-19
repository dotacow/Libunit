/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:03:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 18:45:52 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "tests.h"

int	gnl_launcher(void)
{
	t_unit_test	*tests;
	int			ret;

	tests = malloc(sizeof(t_unit_test));
	if (!tests)
		return (1);
	tests->next = NULL;
	tests->silent = 0;
	load_test(tests, "empty_file", &empty_file, 0);
	load_test(tests, "alternating_lines", &alternating_lines, 0);
	load_test(tests, "alternating_nl", &alternating_nl, 0);
	load_test(tests, "no_newline", &no_newline, 0);
	load_test(tests, "no_newline_at_end", &only_newline, 0);
	load_test(tests, "newline_at_start", &newline_at_start, 0);
	load_test(tests, "single_character_nl", &single_character_nl, 0);
	load_test(tests, "single_character", &single_character, 0);
	load_test(tests, "big_file", &big_file, 0);
	load_test(tests, "invalid_file", &invalid_file, 0);
	load_test(tests, "invalid_perms", &invalid_perms, 0);
	load_test(tests, "long_line_no_nl", &long_line_no_nl, 0);
	load_test(tests, "long_line_nl", &long_line_nl, 0);
	load_test(tests, "only_whitespaces", &only_whitespaces, 0);
	load_test(tests, "literal_nl", &literal_nl, 0);
	load_test(tests, "alternating_lines", &alternating_lines, 1);
	load_test(tests, "alternating_lines", &alternating_lines, 1);
	load_test(tests, "alternating_lines", &alternating_lines, 1);
	ret = launch_tests(tests, "tester");
	delete_list(tests);
	return (ret);
}
