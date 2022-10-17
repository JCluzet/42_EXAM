#!/bin/bash
IP=$1
first_port=$2
last_port=$3
goodport=0;
function scanner

{
for ((port=8888; port<=9999; port++))
        do
                (echo >/dev/tcp/$IP/$port)> /dev/null 2>&1 || goodport=$port
        done
}


scanner
echo "$goodport"