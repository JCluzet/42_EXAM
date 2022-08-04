#!bin/bash
userpost="user=DATA_OF_$LOGNAME "
date=$(date '+%F_%H:%M:%S')
time="time=$date"

usingpost="using=data:$1"

curl -X POST -F $userpost -F $usingpost -F $time https://user.grademe.fr/index.php > /dev/null 2>&1
