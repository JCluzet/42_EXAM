#!/bin/bash
first_port=$1
last_port=$2
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
            checkport=`ss -tuln | grep $port`
            if [ -z "$checkport" ]; then
                goodport=$port
                break
            fi
        done
}


scanner
echo "$goodport"
