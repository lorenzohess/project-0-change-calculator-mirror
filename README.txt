
# Change Calculator

This CLI change calculator can replace the change-calculation functionality of a cash register (see project requirements [PDF](change_calculator.pdf).) It prints exact change given a purchase amount and the amount paid. We print change in US currency with maximum highest denomination first using $5, $1, .

Available at [gitlab.com/lorenzohess/project-0-change-calculator](https://gitlab.com/lorenzohess/project-0-change-calculator).


## Technical Requirements

No arrays, pointers, or global variables.


## Pseudocode

See [pseudocode.txt](pseudocode.txt).


## Dependencies

The C `stdio` library.


## Build

Compile with GCC. Suggested command: `gcc change_calculator.c -Wall -o getChange`.


## Usage

In Bash, run with: `./getChange`. Requires executable permissions.

Example:

    $ ./getChange
    Input purchase total:
    10 # total cost is $10
    Input amount paid:
    17.65 # amount paid is $17.65
    Your change is $7.65
      1 - 5D
      2 - 1D
      2 - Q
      1 - D
      1 - N

Validate that amount paid >= purchase total:

    $ ./getChange
    Input purchase total:
    10
    Input amount paid:
    8
    Insufficient payment.

