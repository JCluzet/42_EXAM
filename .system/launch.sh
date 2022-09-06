# if there is a a.out file in the current directory, delete it
if [ -f .system/a.out ]; then
    ./.system/a.out
    exit 0
fi

# if the file .system/data_persistence.txt exists, remove it
if [ -f .system/.devmake.err]; then
    rm .system/.devmake.err
fi

MANGENTA="\033[35m"
BOLD="\033[1m"
RED="\033[31m"
WHITE="\033[37m"
GRAY="\033[90m"
RESET="\033[0m"
spin[0]="-"
spin[1]="\\"
spin[2]="|"
spin[3]="/"

bash .system/maj.sh

g++ .system/exercice.cpp .system/main.cpp .system/menu.cpp .system/exam.cpp .system/utils.cpp .system/grade_request.cpp .system/data_persistence.cpp -lreadline -o .system/a.out > .system/.devmake.err 2>.system/.devmake.err &
PID=$!

clear
echo -ne "$WHITE$BOLD"
echo -ne "Compilation of$BOLD$MANGENTA 42_EXAM v2 $BOLD$WHITE "
# while there is no a.out file in the current directory, wait
while [ ! -f .system/a.out ]; do
  for i in "${spin[@]}"
  do
        echo -ne "\b$i"
        # if the file .system/data_persistence.txt having more than 1 line, exit
        if [ -f .system/.devmake.err ]; then
        result=$(awk '{t+=length($0)}END{print t}' .system/.devmake.err)
        # echo "$result<<<<"
        if [ "$result" != "" ]; then
            echo ""
            echo ""
            printf "$RED$BOLD"
            printf "Oops !$WHITE$BOLD Something went wrong during the compilation...\n"
            echo "Please make a report on Github repo, make sure to include this :"
            echo ""
            printf "      - Your OS:$RESET$GRAY $(uname -a)$WHITE$BOLD\n"
            printf "      - The error message:$RESET$GRAY\n"
            cat .system/.devmake.err
            printf "$WHITE$BOLD"
            echo ""
            echo "Thanks for your contribution !"
            exit 0
        fi
        fi
        sleep 0.1
  done
done
echo ""
echo ""

echo "Done!"
# rm .system/.devmake.err 2>/dev/null
cp .system/a.out a.out 
./a.out

