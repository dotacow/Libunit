
all: tests realtests

tests:
	make test -C tests
	@echo "tester tests completed"

realtests:
	make test -C real-tests
	@echo "realtests completed"

.PHONY: all tests realtests