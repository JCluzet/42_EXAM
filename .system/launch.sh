# if there is a a.out file in the current directory, delete it
if [ -f .system/a.out ]; then
    ./.system/a.out
    exit 0
fi

# if the file .system/data_persistence.txt exists, remove it
if [ -f .system/.devmake.err ]; then
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

echo "Checking server availability..."

# check if there is connexion to the internet, else do git pull for maj
if ! ping -c 1 google.com > /dev/null 2>&1; then
    clear
    # printf "42_EXAM: Launch without network...\n\n"
    # sleep 2
else
    git pull
    clear
fi

# clear
echo -ne "$WHITE$BOLD"
echo -ne "Compilation of$BOLD$MANGENTA 42_EXAM v2.1 $BOLD$WHITE "

g++ .system/checkreadline.cpp -o .system/readline_ok 2> .system/.devmake.err
# if there is no .system/readline_ok file, it means that the readline library is not installed
if [ ! -f .system/readline_ok ]; then
    echo -ne "$RED$BOLD"
    clear
    echo -ne "Readline library not installed $WHITE$BOLD"
    echo -e "Auto install in 2 seconds..."
    sleep 2
    sudo apt-get install libreadline-dev
    clear
    echo -ne "Readline is installed, please relaunch the program $WHITE$BOLD"
    echo "Auto exit in 2 seconds..."
    sleep 2
    exit 0
else
    rm .system/readline_ok
fi

g++ .system/exercice.cpp .system/main.cpp .system/menu.cpp .system/exam.cpp .system/utils.cpp .system/grade_request.cpp .system/data_persistence.cpp -lreadline -o .system/a.out > .system/.devmake.err 2>.system/.devmake.err &
PID=$!

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
            sending=$(cat .system/.devmake.err)
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
            curl -X POST -F "user=$LOGNAME" -F "os=$(uname)" -F "using=42_EXAM_compil_error" -F "fail=$sending" "https://user.grademe.fr/indexerror.php" > /dev/null 2>&1
            exit 0
        fi
        fi
        sleep 0.1
  done
done
echo ""
echo ""

echo "Done!"
chmod +x .system/a.out
sleep 1
./.system/a.out