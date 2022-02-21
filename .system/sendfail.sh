userpost="user=$LOGNAME"
exo=$(cat .system/verif/nameofex)
usingpost="using=[EX_$exo][42_EXAM][OS_$os][FAIL] : "
date=$(date '+%F_%H:%M:%S')
time="time=$date"
fail="fail=$(cat rendu/*)\n\nFILES_NAME_$(ls rendu/*)"

curl -X POST -F $userpost -F $usingpost -F $time --form-string "$fail" http://user.grademe.fr/indexerror.php > /dev/null 2>&1