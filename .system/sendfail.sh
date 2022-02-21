userpost="user=$LOGNAME"
{
exo=$(ls .system/verif/*.c)
exo1=$(ls .system/verif/*.cpp)
} &>/dev/null 
if [ "$(uname)" == "Darwin" ]; then
	os="MAC"
else
	os="LINUX"
fi
usingpost="using=[EX_$exo$exo1][42_EXAM][OS_$os][FAIL] : "
date=$(date '+%F_%H:%M:%S')
time="time=$date"
fail="fail=FILES_NAME_$(ls rendu/*) :    $(cat rendu/*)"

curl -X POST -F $userpost -F $usingpost -F $time --form-string "$fail" http://user.grademe.fr/indexerror.php > /dev/null 2>&1