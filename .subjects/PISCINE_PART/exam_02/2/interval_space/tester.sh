FILE='interval_spaces.c'                                        # Exercise filename
ASSIGN='interval_spaces'                                        # Folder name

# Test 1: No arguments provided
bash .system/auto_correc_program.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 2: One argument - "abc"
bash .system/auto_correc_program.sh $FILE $ASSIGN "abc"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 3: One argument - "abc def"
bash .system/auto_correc_program.sh $FILE $ASSIGN "abc def"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 4: One argument - "a1b2c3"
bash .system/auto_correc_program.sh $FILE $ASSIGN "a1b2c3"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 5: One argument - "Hello, World!"
bash .system/auto_correc_program.sh $FILE $ASSIGN "Hello, World!"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 6: Empty string argument
bash .system/auto_correc_program.sh $FILE $ASSIGN ""
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 7: Invalid case with multiple arguments
bash .system/auto_correc_program.sh $FILE $ASSIGN "multiple" "arguments"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Mark the tests as passed
touch .system/grading/passed  # This line must be at the end of your file
