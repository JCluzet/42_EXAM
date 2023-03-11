# How to contribute by adding more exercices:

You can add your own exercises by simply creating a folder for the exercise in the `.subjects` folder.

👉 42_EXAM automatically detects the exercises available in the folders, so you don't have to change anything in the program.

To add an exercise you have to create a folder with the name of the exercise in its respective level (browse the .subjects folder to understand)

--------
 
🔖 For an exercise to be complete, you must add:

- A subject named `subject.en.txt` in a folder `attachment` (you can add other files that will be given to the student during the exercise)
- The exercise solution (example : fprime.c) 
⚠️ WARNING: The exercise must be perfect because it will be used by 42_EXAM to know if the rendering is correct.
- The correction file `tester.sh` which is the file that allows you to send the inputs to test what you want. 

``` 
fprime
 |
 |__attachment
 |    |__subjects.en.txt
 |    |__(other files give to students)
 |
 |__fprime.c (The exercice must be perfect)
 |
 |__main.c (if exercise is a function and not a program)
 |
 |__tester.sh (details below)

``` 



🔎 There are two types of `tester.sh` files.
You should use the first one if your exercise is a **program**, and therefore does not need a main.

You must use the second if your exercise is a **function**, and therefore needs a main (you will have to provide the main in your exercise file)

Here is what the first tester.sh file looks like *(PROGRAM EXERCISE)*:

``` 
FILE='fprime.c'                                                  # exercise filename
ASSIGN='fprime'                                                  # folder name

bash .system/auto_correc_program.sh $FILE $ASSIGN                # This partition is a test, just add as much arguments you need (Here there is no arguments)
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN  "225225"       # A test with 1 argument who is "225225"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "8333325" "42"  # A test with 2 arguments which are "8333325" and "42"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

# There are 3 tests here, but you can add as many as you want.

touch .system/grading/passed;     # This line must be at the end of your file
```

And here is what the second tester.sh file looks like *(FUNCTION EXERCICE)*:

 `👉 The only change is auto_correc_program who become auto_correc_main`

``` 
FILE='fprime.c'                                                  # exercice filename
ASSIGN='fprime'                                                  # folder name

bash .system/auto_correc_main.sh 
$FILE $ASSIGN                # This partition is a test, just add as much arguments you need (In this example there is no arguments)
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh 
$FILE $ASSIGN  "225225"       # A test with 1 argument which is "225225"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh 
$FILE $ASSIGN "8333325" "42"  # A test with 2 arguments which are "8333325" and "42"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

# There are 3 tests here, but you can add as many as you want.

touch .system/grading/passed;     # This line must be at the end of your file
```



✅ Once you have added a new exercise, you can test it using 42_EXAM (If you don't find it, use the command new_ex until you find it)

Once the exercise is perfectly added, you can ask for it to be added to the program on Github by making a pull request 😎
🔎 Here is a video that will help you: [How to easily make a pull request](https://www.youtube.com/watch?v=rgbCcBNZcdQ)

If your pull request is accepted, you will have your name in the ReadMe as a contributor 🥳

😩 If you have any problem during the creation of an exercise, do not hesitate to ask a question.
I will usually answer within the hour.

Thanks for your contribution ❤️
