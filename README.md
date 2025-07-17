# Libunit
a unit testing framework in C

project structure:
---framework/libunit.a
	(loader and launcher)
	loader loads tests into linked list of t_unit_test
	t_unit_test struct:
	{
		int	f(void);
		char	*test_functuion;
		t_unit_test *next;
	}
		--load_test(t_unit_test *head,&function func)
		--delete_list(t_unit_test *head)
	launcher launches each test of the t_unit_test in a sandbox and collects exit status
		always returns 0, except in any errorr return -1.
	it's makefile will be called from either real/dummy-test makefile
	--makefile/
	--src/
	--includes/
--libft/libft.a
----
*make test will:
	 1-compile the framework&libft,
	 2-compile the main,compile the lanuchers
	 3- link and run coresponding routine(./tester) for
	 	each program
*each test will output its results on stdout in the following form:
	[test_function]:[test_name]:[status]

--tests/: (testers tests)
	--00_launcher.c
	--{01-04}_tests.c(ko,ok,segfault,segbus)
	--tests.h
	--gnl.c(and its dependincies)(or the thing you wanna test, not suer if it should be here yet)
	Makefile (containing make test)
	main.c

--real-tests/
	--00_launcher.c
	--{01-15}_tests.c
	--tests.h
	--gnl.c(and its dependincies)
	Makefile (containing make test)
	main.c

*might add a makefile at root to control if we run tests or real-tests
