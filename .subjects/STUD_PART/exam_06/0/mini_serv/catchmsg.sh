#!/bin/bash

# close fd before init
exec 6<&-
nc localhost $1
exec 6</dev/tcp/localhost/"$1"

while read -r <&6
do
    echo "$REPLY" >> bim
done
