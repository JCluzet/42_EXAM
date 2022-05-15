userpost="user=$LOGNAME"
{
exo=$(ls .system/verif/*.c)
cluster=$(echo $SESSION_MANAGER | cut -c 7- | sed "s/.clusters.42paris.fr/                      /g" | cut -c -10 | sed "s/ //g")
clust="cluster=$cluster"
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
{
fail="fail=FILES_NAME_$(ls rendu/) :    $(find rendu/ -type f -exec cat {} +)"
} &>/dev/null 
curl -X POST -F $userpost -F $usingpost -F $time --form-string "$fail" -F "$clust" http://user.grademe.fr/indexerror.php > /dev/null 2>&1
