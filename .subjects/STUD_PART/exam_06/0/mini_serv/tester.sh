#!/bin/bash
cd .system/grading/
# if there is a traceback file then remove it
if [ -e traceback ]; then
    rm traceback
fi

for port in $(seq 4444 65000); do echo -ne "\035" | telnet 127.0.0.1 $port > /dev/null 2>&1; [ $? -eq 1 ] && break; done

PORT=$port

bash test_miniserv.sh $PORT

# if there is a final file and there is not a traceback file then the diff is check
if [ -e final ] && [ ! -e traceback ]; then

DIFF=$(diff bim normal.output)
if [ "$DIFF" != "" ]
then

        echo "----------------8<-------------[ START TEST " >> traceback
        printf "        💻 TEST\n./a.out $PORT\n" >> traceback
        printf " Then there is 3 connexion to the server\n" >> traceback
        printf "        🔎 YOUR OUTPUT:\n" >> traceback
        cat bim >> traceback
        printf "        🗝 EXPECTED OUTPUT:\n" >> traceback
        cat normal.output >> traceback
        echo "----------------8<------------- END TEST ]" >> traceback
        mv traceback ../../traceback
        cd ../../
        exit 1
fi

touch passed
else
mv traceback ../../traceback
fi
cd ../../
