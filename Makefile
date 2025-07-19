
all: tests realtests

allclean: testsclean realtestsclean
allmake: testmake realtestsmake
allfclean: testsfclean realtestsfclean
allre: testsre realtestsre

testsclean:
	make -C clean tests
testsmake:
	make -C all tests
testsfclean:
	make -C fclean tests
testsre:
	make -C re tests
tests:
	make test -C tests

realtestsclean:
	make -C clean realtests
realtestsmake:
	make -C all realtests
realtestsfclean:
	make -C fclean realtests
realtestsre:
	make -C re realtests

realtests:
	make test -C real-tests
	@echo "realtests completed"

.PHONY: all allclean allmake allfclean allre testsclean testsmake testsfclean testsre tests realtestsclean realtestsmake realtestsfclean realtestsre realtests