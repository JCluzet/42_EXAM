# pgcd

## Conceptual Overview
### The Problem
We are asked to write a program that is given two strings as argument, each representing a positive whole number. It finds the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) and prints it.

[ [Full Subject](subject.en.txt) | [Examples](examples.txt) ]

### Approach
Convert the arguments from strings to ints. Starting with a test number equal to the smaller of the two numbers passed as argument, check if the test value divides both numbers evenly. If it does, the test number is the greatest common divisor; print it and exit. Otherwise, subtract 1 from the test number and test again until until the GCD is found.

This approach can be optimized further in the case where the smaller number given as argument does not divide the larger one evenly. In this case, instead of subtracting 1 from the test number, it can be divided by 2 and added to 1 before continuing the loop as described above. Because an optimized solution is not required, I use the simpler version here.

## Pseudocode
```
If more or less than 2 arguments have been given
	print a newline and exit
set int x to integer value of first argument
set int y to integer value of second argument
set int test to the smaller of x and y
while test is greater than 0
	if test divides x evenly and test divides y evenly
		print test and exit
	else
		set test to its own value minus 1
print a newline and exit.
```

## Test cases
It is particularly important to test cases in which one of the arguments is 1, one of the arguments is a divisor of the other, and in which the GCD of the numbers is 1.
```
./pgcd "920556" "1980488"
./pgcd "1803684" "3539916"
./pgcd "15" "18"
./pgcd "6" "18"
./pgcd "13" "17"
./pgcd "1" "17"
```