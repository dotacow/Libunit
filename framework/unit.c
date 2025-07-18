/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:41:03 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/18 15:59:42 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int load_test(t_unit_test *tests, char *testname, int (*f)(void))
{
	t_unit_test *head;
	t_unit_test *new;

	new = malloc(sizeof(t_unit_test));
	if (!new)
		return (1);
	new->next = NULL;
	new->testname = testname;
	new->f = f;
	head = tests;
	while(head->next)
		head = head->next;
	head->next = new;
	return (0);
}

void delete_list(t_unit_test *tests)
{
	t_unit_test *temp;
	temp = tests;
	while (tests)
	{
		temp = tests->next;
		if (tests)
			free(tests);
		tests = NULL;
		tests = temp;
	}
}

static	int catch_signal(t_unit_test *test,int status)
{
	int exitcode;

	if (WIFEXITED(status))
	{
		exitcode = WEXITSTATUS(status);
		if (exitcode == 1)
		{
			printf("%s: %s : [KO]\n",test->testedname,test->testname);
			return (-1);
		}
		else
			printf("%s: %s : [OK]\n",test->testedname,test->testname);
		return(0);
	}
 	if (WIFSIGNALED(status))
	{
		exitcode = WTERMSIG(status);
		if (exitcode == SIGBUS)
			printf("%s: %s : [SIGBUS]\n",test->testedname,test->testname);
		else if (exitcode == SIGSEGV)
			printf("%s: %s : [SIGSEGV]\n",test->testedname,test->testname);
		else
			printf("%s: %s : [KO]\n",test->testedname,test->testname);
	}
	return (-1);
}

int		launch_tests(t_unit_test *tests)
{
	pid_t wpid;
	int ret;
	int exitcode;
	int status;

	exitcode = 0;
	while (tests)
	{
		wpid = fork();
		if (wpid == -1)
			return (wpid);
		if (wpid)
		{
			wait(&status);
			ret = catch_signal(tests, status);
			if (ret != 0)
				exitcode = -1;
		}
		else
			exit(tests->f());
		tests = tests->next;
	}
	return (exitcode);
}
