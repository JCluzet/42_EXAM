Assignment name  : microshell
Expected files   : microshell.c
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Write a program that will behave like executing a shell command
- The command line to execute will be the arguments of this program
- Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)
- You must implement "|" and ";" like in bash
	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"
- Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
	- a cd command will never be immediately followed or preceded by a "|"
- You don't need to manage any type of wildcards (*, ~ etc...)
- You don't need to manage environment variables ($BLA ...)
- If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit
- If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)
- Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!
_____________________________________________________________________________________________________________________________

Напишите программу, которая будет вести себя как выполнение команды оболочки
- Командной строкой для выполнения будут аргументы этой программы
- Путь исполняемого файла будет абсолютным или относительным, но ваша программа не должна создавать путь (например, из переменной PATH)
- Вы должны реализовать " | "и"; " как в bash
- мы никогда не будем пробовать " | "сразу после или перед ничем или" | " или ";"
- Ваша программа должна реализовывать встроенную команду cd только с путем в качестве аргумента (без '-' или без параметров)
- если cd имеет неправильный номер аргумента, ваша программа должна напечатать в STDERR "error: cd: bad arguments", за которым следует '\n'
- если cd не удался, ваша программа должна напечатать в STDERR "error: cd: cannot change directory to path_to_change", за которым следует '\n ' с path_to_change, замененным аргументом на cd
- команда cd никогда не будет немедленно следовать или предшествовать команде "|"
- Вам не нужно управлять любыми типами подстановочных знаков ( * , ~ и т. д...)
- Вам не нужно управлять переменными окружения ($BLA ...)
- Если системный вызов, кроме execve и chdir, возвращает ошибку, ваша программа должна немедленно напечатать "error: fatal" в STDERR, за которым следует '\n', и программа должна выйти
- Если execve не удалось, вы должны напечатать "error: cannot execute executable_that_failed" в STDERR, а затем '\n ' с executable_that_failed, замененным путем неудачного исполняемого файла (это должен быть первый аргумент execve)
- Ваша программа должна уметь управлять более чем сотнями"|", даже если мы ограничим количество "открытых файлов" менее чем 30.

Подсказки:
Не забудьте передать переменную окружения в execve

Подсказки:
Не допускайте утечки файловых дескрипторов!
