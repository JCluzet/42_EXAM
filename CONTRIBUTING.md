# How to contribute by adding more exercices:

You can add your own exercises simply by creating a folder for the exercise in the `.subjects` folder.

👉 42_EXAM automatically detects the exercises available in the folders, so you don't have to change anything in the program.

To add an exercise, you have to create a folder with the name of the exercise in the folder corresponding to the level (browse the .subjects folder to understand)
 
For an exercise to be complete, you must add :

- A subject named `subject.en.txt` in a folder `attachments` (you can add other files that will be given to the student during the exercise)
- The exercise in question (example : prime.c) ⚠️ WARNING: the exercise must be perfect because it will be used by 42_EXAM to know if the rendering is correct.
- The correction file `tester.sh` This is the file that allows you to send the tests you want. 

There are two types of `tester.sh` files.
You should use the first one if your exercise is a **program**, and therefore does not need a main.

You must use the second if your exercise is a **function**, and therefore needs a main (you will have to provide the main in your exercise file)

Here is what the first tester.sh file looks like (PROGRAM EXERCICE):
