#!/bin/bash
IP=$1
first_port=$2
last_port=$3
goodport=0;
if [ -z "$first_port" ]
then
        first_port=8888
fi
if [ -z "$last_port" ]
then
        last_port=9999
fi
function scanner

{
for ((port="$first_port"; port<="$last_port"; port++))
        do
                (echo >/dev/tcp/"$IP"/"$port")> /dev/null 2>&1 || goodport=$port
        done
}


scanner
echo "$goodport"