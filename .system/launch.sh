version="2.1"

# if there is a a.out file in the current directory, delete it
if [ -f .system/a.out ]; then
    sleep 0.1
    rm ./.system/a.out
    exit 0
fi

# if the file .system/data_persistence.txt exists, remove it
if [ -f .system/.devmake.err ]; then
    rm .system/.devmake.err
fi

if [ -f .system/readline_ok ]; then
    rm .system/readline_ok
fi

export LOGNAMELOG42EXAM="$LOGNAME"

MANGENTA="\033[35m"
BOLD="\033[1m"
CLEAR_LINE="\033[2K"
LINE_UP="\033[1A"
RED="\033[31m"
WHITE="\033[37m"
GRAY="\033[90m"
BLUE="\033[34m"
GREEN="\033[32m"
RESET="\033[0m"
spin[0]="⠁"
spin[1]="⠃"
spin[2]="⠇"
spin[3]="⠧"
spin[4]="⠷"
spin[5]="⠿"
spin[6]="⠷"
spin[7]="⠧"
spin[8]="⠇"
spin[9]="⠃"

if [ "$1" != "grade" ]; then
    if [ "$1" != "gradejustinstall" ]; then
        clear
    fi
fi

ping -c 1 google.com >/dev/null 2>&1 &
PID=$!

while [ -d /proc/$PID ]; do
    for i in "${spin[@]}"; do
        echo -ne "$LINE_UP$WHITE$i$RESET Checking server availability\n"
        for i in {1..32}; do
            printf "\b"
        done
        sleep 0.1
    done
done

if [ "$1" != "gradejustinstall" ]; then

    if ! ping -c 1 google.com >/dev/null 2>&1; then
        printf "$LINE_UP$CLEAR_LINE$RED"
        echo -ne "✗$RESET Checking server availability$WHITE$BOLD\n"
        echo -ne "  ➫ Local launch\n\n"
    else
        git pull >/dev/null 2>&1 &
        printf "$LINE_UP$CLEAR_LINE$RED"
        # clear
        printf "$GREEN$BOLD"
        echo -ne "✔$RESET You have the last version$GREEN$BOLD v$version\n\n"

    fi

fi

# sleep 1000

# check if there is connection to the internet, else do git pull for maj

# Check if readline is installed, if not, install it
g++ .system/checkreadline.cpp -o .system/readline_ok 2>.system/.devmake.err &

if [ ! -f .system/readline_ok ]; then
    for i in "${spin[@]}"; do
        echo -ne "$LINE_UP$WHITE$i$WHITE$BOLD Checking readline library\n"
        for i in {1..29}; do
            printf "\b"
        done
        sleep 0.1
    done
fi

printf "$LINE_UP$CLEAR_LINE$GREEN$BOLD"
echo -ne "✔$RESET Checking readline library$WHITE$BOLD\n\n"

if [ ! -f .system/readline_ok ]; then
    # clear
    printf "$LINE_UP$CLEAR_LINE$RED"
    printf "$LINE_UP$CLEAR_LINE$RED"
    echo -ne "✗$RESET Readline is not installed$WHITE$BOLD\n"
    echo -ne "$RED$BOLD"
    echo -ne "Readline library not installed $WHITE$BOLD\n"
    echo -e " ➫ Auto install in 2 seconds...\n"
    sleep 2
    sudo apt-get update
    sudo apt-get install libreadline-dev 2>.system/.devmake.err 1>.system/.devmake.err &
    PID=$!

    while [ -d /proc/$PID ]; do
        for i in "${spin[@]}"; do
            echo -ne "$LINE_UP$WHITE$i$WHITE$BOLD libreadline-dev installation using apt-get\n"
            for i in {1..44}; do
                printf "\b"
            done
            sleep 0.1
        done
    done

    printf "$LINE_UP$CLEAR_LINE$GREEN$BOLD"
    # echo -ne "✔$RESET Readline installation using apt-get$WHITE$BOLD\n\n"

    # check if the compilator c++ is installed



    # clear
    g++ .system/checkreadline.cpp -o .system/readline_ok 2>.system/.devmake.err
    # if there is no .system/readline_ok file, it means that the readline library is not installed
    if [ ! -f .system/readline_ok ]; then
        echo -ne "$RED$BOLD"
        # clear
        echo -ne "Readline installation error using apt-get... $WHITE$BOLD"
        echo -e "Try to install with yum..."
        sleep 1
        sudo yum install readline
        clear


        g++ .system/checkreadline.cpp -o .system/readline_ok 2>.system/.devmake.err





        if [ ! -f .system/readline_ok ]; then
            echo -ne "Can't install readline library... $WHITE$BOLD"
            echo -ne "1. Check if g++ is installed\n"
            echo -ne "2. Check if libreadline-dev is installed\n"
            echo -e "Please install it manually or write an Issue on Github..."
            exit 1
        fi
        # clear
    fi
    echo -ne "✔$RESET libreadline-dev installation using apt-get$WHITE$BOLD\n\n"
    # echo -ne "Readline is installed, please relaunch the program $WHITE$BOLD"
    # echo "Auto exit in 2 seconds..."
    # sleep 2
    # exit 0
fi

rm -rf .system/readline_ok
# sleep 1000
# clear
# echo -ne "$RESET"
# echo -ne "Compilation of$BOLD$MANGENTA 42_EXAM v2.1 $RESET "
# ===============================================

g++ .system/exercise.cpp .system/main.cpp .system/menu.cpp .system/exam.cpp .system/utils.cpp .system/grade_request.cpp .system/data_persistence.cpp -lreadline -o .system/a.out >.system/.devmake.err 2>.system/.devmake.err &
PID=$!

# while there is no a.out file in the current directory, wait
while [ ! -f .system/a.out ]; do
    for i in "${spin[@]}"; do
        echo -ne "$LINE_UP$WHITE$i$WHITE$BOLD Compilation of$BOLD$MANGENTA 42_EXAM $RESET\n"
        if [ -f .system/.devmake.err ]; then
            result=$(awk '{t+=length($0)}END{print t}' .system/.devmake.err)
            # echo "$result<<<<"
            if [ "$result" != "" ]; then
                sending=$(cat .system/.devmake.err)
                printf "$LINE_UP$CLEAR_LINE$RED"
                echo -ne "✗$RESET Compilation of$BOLD$MANGENTA 42_EXAM $RESET\n"
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
        for i in {1..30}; do
            printf "\b"
        done
    done
done

check_package() {
    if ! command -v "$1" &>/dev/null; then
        return 1
    fi
}

# Vérification de clang
if ! check_package "clang"; then
    echo "Le compilateur clang n'est pas installé sur votre système."
    echo "Veuillez l'installer pour continuer."
    exit 1
fi

# Vérification de clang++
if ! check_package "clang++"; then
    echo "Le compilateur clang++ n'est pas installé sur votre système."
    echo "Veuillez l'installer pour continuer."
    exit 1
fi

# Vérification de gcc
if ! check_package "gcc"; then
    echo "Le compilateur gcc n'est pas installé sur votre système."
    echo "Veuillez l'installer pour continuer."
    exit 1
fi

# Vérification de g++
if ! check_package "g++"; then
    echo "Le compilateur g++ n'est pas installé sur votre système."
    echo "Veuillez l'installer pour continuer."
    exit 1
fi

printf "$LINE_UP$CLEAR_LINE$GREEN$BOLD"
echo -ne "✔$RESET Compilation of$BOLD$MANGENTA 42_EXAM $RESET\n"

# echo "Done!"
chmod +x .system/a.out
# sleep 1



# check if USER is set, if not, set it
if [ -z "$USER" ]; then
    #if there is a .system/.env file, read it and set the variable USER
    if [ -f .system/.env ]; then
        export USER=$(cat .system/.env)
        echo "Variable USER set to $USER ✅"
        ./.system/a.out
        exit 0
    fi
    echo "USER is not set, you must enter your 42 login to use this program "
    echo -ne "Enter your 42 login : "
    read -r user_login        # Lire le login entré par l'utilisateur
    export USER="$user_login" # Créer la variable d'environnement USER
    echo "USER=$user_login" >.system/.env
    echo "Variable USER set to $USER ✅"
fi

./.system/a.out
