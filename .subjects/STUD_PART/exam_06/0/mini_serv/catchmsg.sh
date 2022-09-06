#!/bin/bash

nc -l localhost $1
exec 6<>/dev/tcp/localhost/$1

while read <&6
do
        echo "$REPLY" >> bim
done