
all: tests realtests

allclean: testsclean realtestsclean
allmake: testmake realtestsmake
allfclean: testsfclean realtestsfclean
allre: testsre realtestsre

testsclean:
	make clean -C tests
testsmake:
	make all -C tests
testsfclean:
	make fclean -C tests
testsre:
	make re -C tests
tests:
	make test -C tests

realtestsclean:
	make  clean -C real-tests
realtestsmake:
	make  all -C real-tests
realtestsfclean:
	make  fclean -C real-tests
realtestsre:
	make  re -C real-tests

realtests:
	make test -C real-tests
	@echo "realtests completed"

.PHONY: all allclean allmake allfclean allre testsclean testsmake testsfclean testsre tests realtestsclean realtestsmake realtestsfclean realtestsre realtests