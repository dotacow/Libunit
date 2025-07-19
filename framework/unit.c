/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:41:03 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/19 16:05:19 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int load_test(t_unit_test *tests, char *testname, int (*f)(void),int silent)
{
	t_unit_test *head;
	t_unit_test *new;

	new = malloc(sizeof(t_unit_test));
	if (!new)
		return (1);
	new->next = NULL;
	new->testname = testname;
	new->f = f;
	new->silent = silent;
	head = tests;
	while(head->next)
		head = head->next;
	head->next = new;
	return (0);
}

void delete_list(t_unit_test *tests)
{
	t_unit_test *temp;
	while (tests)
	{
		temp = tests->next;
		free(tests);
		tests = temp;
	}
}

static	int catch_signal(t_unit_test *test,int status,char *testedname)
{
	int exitcode;

	if (WIFEXITED(status))
	{
		exitcode = WEXITSTATUS(status);
		if (exitcode != 0 && !test->silent)
			ft_printf("%s: %s : [KO]\n",testedname,test->testname);
		if (exitcode == 0)
		{
			if (!test->silent)
				ft_printf("%s: %s : [OK]\n",testedname,test->testname);
			return(0);
		}
	}
 	if (WIFSIGNALED(status))
	{
		exitcode = WTERMSIG(status);
		if (exitcode == SIGBUS && !test->silent)
			ft_printf("%s: %s : [SIGBUS]\n",testedname,test->testname);
		else if (exitcode == SIGSEGV && !test->silent)
			ft_printf("%s: %s : [SIGSEGV]\n",testedname,test->testname);
		else if (!test->silent)
			ft_printf("%s: %s : [KO]\n",testedname,test->testname);
	}
	return (-1);
}

static int child_process(t_unit_test *test,t_unit_test *head)
{
	int (*func)(void);

	func = test->f;
	delete_list(head);
	return (func());
}

int		launch_tests(t_unit_test *tests, char *testedname)
{
	pid_t wpid;
	int exitcode;
	int status;
	t_unit_test *head;

	head = tests;
	exitcode = 0;
	tests = tests->next;
	while (tests)
	{
		wpid = fork();
		if (wpid == -1)
			return (wpid);
		if (wpid)
		{
			wait(&status);
			if (catch_signal(tests, status,testedname) != 0)
				exitcode = -1;
		}
		else
			exit(child_process(tests,head));
		tests = tests->next;
	}
	return (exitcode);
}
