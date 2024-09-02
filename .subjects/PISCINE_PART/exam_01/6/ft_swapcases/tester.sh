FILE='ft_swapcases.c'                                             # Exercise filename
ASSIGN='ft_swapcases'                                              # Folder name

# Test 1: No arguments provided
bash .system/auto_correc_main.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 2: One argument - "Hello World!"
bash .system/auto_correc_main.sh $FILE $ASSIGN "Hello World!"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 3: One argument - "42School"
bash .system/auto_correc_main.sh $FILE $ASSIGN "42School"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 4: Empty string argument
bash .system/auto_correc_main.sh $FILE $ASSIGN ""
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 5: Argument with mixed case and special characters
bash .system/auto_correc_main.sh $FILE $ASSIGN "TeSt123!"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Mark the tests as passed
touch .system/grading/passed;  # This line must be at the end of your file
