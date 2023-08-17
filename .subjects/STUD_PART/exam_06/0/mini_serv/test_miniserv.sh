if [ -f bim ]; then
    rm bim
fi
if [ -f trace ]; then
    rm trace
fi
if [ -f final ]; then
    rm final
fi



clang -o final ../../rendu/mini_serv/mini_serv.c > trace 2>&1
if [ -e final ]; then

./final $1 | cat -e >/dev/null 2>&1 &
PID=$!

sleep 1

if (</dev/tcp/localhost/$1) >/dev/null 2>&1; then
    # Connection successful, port is open
else
    # Connection failed, port is not open
    echo "----------------8<-------------[ START TEST " >> traceback
    # printf "        🔎 YOUR OUTPUT:\n" >> traceback
    # cat trace >> traceback
    printf "        ❌ PORT IS NOT OPEN \n" >> traceback
    printf "        💻2 TEST\n./a.out $1\n" >> traceback
    printf " Using telnet after the server is started\n" >> traceback
    printf "        Cannot connect to port $1\n" >> traceback
    echo "----------------8<------------- END TEST ]" >> traceback
    index=$((index+1))
    exit 1
fi


bash catchmsg.sh $1 >> bim &
PID2=$!

sleep 1

echo "Si vous ne voyez QUE ce message, c'est mauvais signe." | telnet localhost $1
sleep 0.2
echo "Bienvenue sur le test de votre miniserv" | telnet localhost $1
sleep 0.2
echo "Ceci est un message" | telnet localhost $1
sleep 0.2
printf "Voici un texte sans retour a la ligne" | telnet localhost $1
sleep 0.2
echo -n "This is a text without backline at the end" | telnet localhost $1
sleep 0.4
printf "Et voici un texte avec plusieurs\nretours\na\nla\nligne\n" | telnet localhost $1
sleep 0.2

bash test_eof.sh $1
sleep 1

kill $PID
kill $PID2

else

    echo "----------------8<-------------[ START TEST " >> traceback
    printf "        🔎 YOUR OUTPUT:\n" >> traceback
    cat trace >> traceback
    printf "        ❌ COMPILATION ERROR\n" >> traceback
    echo "----------------8<------------- END TEST ]" >> traceback
    index=$((index+1))
fi
    
    # else
    #     echo "----------------8<-------------[ START TEST " >> traceback
    #     printf "        🔎 YOUR OUTPUT:\n" >> traceback
    #     cat trace >> traceback
    #     printf "        ❌ PORT IS NOT OPEN \n" >> traceback
    #     echo "----------------8<------------- END TEST ]" >> traceback
    #     index=$((index+1))
    # fi
# fi