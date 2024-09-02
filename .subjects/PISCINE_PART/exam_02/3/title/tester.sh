FILE='title.c'                                              # Exercise filename
ASSIGN='title'                                              # Folder name

# Test 1: No arguments provided
bash .system/auto_correc_program.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 2: One argument - "hello world"
bash .system/auto_correc_program.sh $FILE $ASSIGN "hello world"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 3: One argument - "this is a test"
bash .system/auto_correc_program.sh $FILE $ASSIGN "this is a test"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 4: One argument - "this is 42a test"
bash .system/auto_correc_program.sh $FILE $ASSIGN "this is 42a test"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 5: One argument - "my title 2024"
bash .system/auto_correc_program.sh $FILE $ASSIGN "my title 2024"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 6: One argument - "MY TITLE"
bash .system/auto_correc_program.sh $FILE $ASSIGN "MY TITLE"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 7: Empty string argument
bash .system/auto_correc_program.sh $FILE $ASSIGN ""
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Test 8: Invalid case with multiple arguments
bash .system/auto_correc_program.sh $FILE $ASSIGN "multiple" "arguments"
if [ -e .system/grading/traceback ]; then
    mv .system/grading/traceback .
    exit 1
fi

# Mark the tests as passed
touch .system/grading/passed  # This line must be at the end of your file