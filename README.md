# Libunit

A lightweight unit testing framework for C that provides a simple and efficient way to run tests in isolated environments with automatic result collection.

## Features

- **Sandboxed Test Execution**: Each test runs in its own process to prevent crashes from affecting other tests
- **Signal Handling**: Detects and reports segmentation faults, bus errors, and other signals
- **Linked List Architecture**: Tests are organized in a dynamic linked list structure for flexible test management
- **Silent Mode**: Option to run tests silently for cleaner output
- **Memory Management**: Automatic cleanup of test structures
- **Cross-platform**: Works on Unix-like systems with fork() support

## Project Structure

```
Libunit/
├── framework/          # Core testing framework
│   ├── libunit.h      # Header file with API definitions
│   ├── unit.c         # Implementation of testing functions
│   ├── libunit.a      # Compiled static library
│   └── Makefile       # Framework build configuration
├── libft/             # Custom C library (dependency)
│   ├── libft.h        # Library header
│   ├── libft.a        # Compiled library
│   └── *.c            # Library source files
├── tests/             # Framework validation tests
│   ├── main.c         # Test runner entry point
│   ├── 00_launcher.c  # Test launcher implementation
│   ├── 01_ok.c        # Passing test example
│   ├── 02_ko.c        # Failing test example
│   ├── 03_sigsev.c    # Segfault test example
│   └── tests.h        # Test declarations
├── real-tests/        # Real-world test examples (get_next_line)
│   ├── main.c         # GNL test runner
│   ├── 00_launcher.c  # GNL test launcher
│   ├── 01-15_*.c      # Various GNL test cases
│   ├── txtfiles/      # Test input files
│   └── tests.h        # GNL test declarations
└── Makefile           # Root build configuration
```

## API Reference

### Core Structure

```c
typedef struct s_unit_test
{
    int (*f)(void);              // Function pointer to test
    int silent;                  // Silent mode flag
    char *testname;             // Name of the test
    struct s_unit_test *next;   // Next test in linked list
} t_unit_test;
```

### Functions

#### `int load_test(t_unit_test *tests, char *testname, int (*f)(void), int silent)`
Loads a test function into the unit test linked list.
- **Parameters**:
  - `tests`: Pointer to the unit test linked list
  - `testname`: Name identifier for the test
  - `f`: Pointer to the function to be tested
  - `silent`: Silent mode flag (0 = verbose, 1 = silent)
- **Returns**: 0 on success, 1 on memory allocation failure

#### `void delete_list(t_unit_test *tests)`
Deletes the unit test structure and frees allocated memory.
- **Parameters**:
  - `tests`: Pointer to the unit test structure to delete

#### `int launch_tests(t_unit_test *tests, char *testedname)`
Launches all tests in the unit test structure in isolated processes.
- **Parameters**:
  - `tests`: Pointer to the unit test structure
  - `testedname`: Name of the tested component
- **Returns**: 0 if all tests passed, -1 if any test failed

## Usage

### Basic Example

```c
#include "framework/libunit.h"

// Your test function - should return 0 for pass, non-zero for fail
int my_test_function(void)
{
    // Your test logic here
    if (some_condition)
        return (0);  // Pass
    return (-1);     // Fail
}

int main(void)
{
    t_unit_test *tests;
    int ret;

    // Initialize test list
    tests = malloc(sizeof(t_unit_test));
    if (!tests)
        return (1);
    tests->next = NULL;
    tests->silent = 0;

    // Load your tests
    load_test(tests, "my_test", my_test_function, 0);
    load_test(tests, "another_test", another_function, 1); // Silent mode

    // Run all tests
    ret = launch_tests(tests, "my_component");

    // Cleanup
    delete_list(tests);
    return (ret);
}
```

## Building and Running

### Build Framework
```bash
make all              # Build both test suites
make tests            # Build and run framework tests
make realtests        # Build and run real-world tests
```

### Individual Components
```bash
make testsmake        # Compile framework tests
make realtestsmake    # Compile real-world tests
make allclean         # Clean all build artifacts
```

## Test Output Format

Tests output results in the following format:
```
[function_name]:[test_name]:[status]
```

Where status can be:
- `OK`: Test passed (exit code 0)
- `KO`: Test failed (non-zero exit code)
- `SIGSEGV`: Segmentation fault detected
- `SIGBUS`: Bus error detected
- Other signal names as appropriate

## Examples

The project includes two test suites:

1. **Framework Tests** (`tests/`): Basic validation of the testing framework itself
2. **Real Tests** (`real-tests/`): Comprehensive tests for `get_next_line` function

### Running Framework Tests
```bash
cd tests
make test
```

### Running Real-World Tests
```bash
cd real-tests
make test
```

## Dependencies

- **libft**: Custom C library providing utility functions
- **Standard C Library**: malloc, fork, wait, signal handling
- **POSIX**: Unix-like system with process management support

## Contributing

When adding new tests:
1. Create test functions that return 0 for pass, non-zero for fail
2. Add function declarations to the appropriate `tests.h` file
3. Load tests in the launcher using `load_test()`
4. Update Makefile if adding new source files

## License

This project is part of educational coursework and follows standard academic usage guidelines.
