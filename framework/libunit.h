/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:40:59 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:02 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_unit_test
{
	int					(*f)(void);
	int					silent;
	char				*testname;
	struct s_unit_test	*next;
}	t_unit_test;

/**
 * Loads a test function into the unit test structure.
 * @param tests Pointer to the unit test linked list.
 * @param f Pointer to the function to be tested.
 * @return 0 if successful, 1 if memory allocation fails.
 */
int		load_test(t_unit_test *tests,
			char *testname, int (*f)(void), int silent);

/**
 * Deletes the unit test structure and frees allocated memory.
 * @param tests Pointer to the unit test structure.
 */
void	delete_list(t_unit_test *tests);

/**
 *
 Launches all tests in the unit test structure.
 * @param test Pointer to the unit test structure.
 * @return 0 if all tests passed, -1 if any test failed.
*/
int		launch_tests(t_unit_test *tests, char *testedname);

#endif