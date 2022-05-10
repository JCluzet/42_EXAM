#!bin/bash
userpost="user=FEEDBACK_OF_$LOGNAME>contact?$2"
date=$(date '+%F_%H:%M:%S')
time="time=$date"

usingpost="using=Feedback:$1"

curl -X POST -F $userpost -F $usingpost -F $time https://user.grademe.fr/index.php > /dev/null 2>&1
