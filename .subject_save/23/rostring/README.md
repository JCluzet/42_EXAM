# rostring

## Conceptual Overview
### The Problem
We are asked to write a program that is given a string as argument. It prints the 2nd through last words followed by the first word, with exactly one space between the words printed.

[ [Full Subject](subject.en.txt) | [Examples](examples.txt) ]

### Approach
Create a huge array of pointers to char. Step through the string passed as argument, converting spaces & tabs to '\0', and as the beginning of each word is found, store a pointer to it in the array. Print the 2nd through last words in the array followed by a space, then print the first word.

This approach is sloppy and tedious to code, but easy to debug.

## Pseudocode
```
If exactly 0 arguments have been given
	print a newline and exit
set char *str to the beginning of the first argument
create an array named "words" containing several thousand char * pointers initialized to NULL
set int i to 0
while str points to a non-'\0' character
	while str points to a whitespace, non-'\0' character
		set the character pointed to by str to '\0'
		increment str forward one character
	if str points to a non-'\0' character
		set element i in the array words to the value of str
	while str points to a non-whitespace, non-'\0' character
		increment str forward one character
	if str points to a non-'\0' character
		set i to its own value plus 1
set int i to 1
while element i of the array words is a non-NULL pointer
	print the string pointed to by element i of words
	set i to its own value plus 1
if element 0 of the array words is a non-NULL pointer
	print the string pointed to by element 0 of words
print a newline
```

## Test cases
```
./rostring "Que la      lumiere soit et la lumiere fut"
./rostring "     AkjhZ zLKIJz , 23y"
./rostring "first" "2" "11000000"
./rostring "abc"
./rostring " abc"
./rostring "abc "
./rostring "abc def"
./rostring "abc  def   ghi    "
./rostring ""
./rostring " "
```