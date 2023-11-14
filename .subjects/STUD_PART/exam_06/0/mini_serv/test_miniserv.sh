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
#PID=$!

sleep 1

PORTOPEN=`ss -tuln | grep "$1"`

# if it's open, then we can test the program
if [ -z "$PORTOPEN" ]; then
    echo "----------------8<-------------[ START TEST " >> traceback
    # printf "        🔎 YOUR OUTPUT:\n" >> traceback
    # cat trace >> traceback
    printf "        ❌ PORT IS NOT OPEN \n" >> traceback
    printf "        💻 TEST\n./a.out $1\n" >> traceback
    printf " Using nc after the server is started\n" >> traceback
    printf "        Cannot connect to port $1\n" >> traceback
    echo "----------------8<------------- END TEST ]" >> traceback
    index=$((index+1))
    exit 1
fi


bash catchmsg.sh $1 >> bim &
#PID2=$!

sleep 1

echo "Si vous ne voyez QUE ce message, c'est mauvais signe." | nc -q 0 localhost $1
sleep 0.2
echo "Bienvenue sur le test de votre miniserv" | nc -q 0 localhost $1
sleep 0.2
echo "Ceci est un message" | nc -q 0 localhost $1
sleep 0.2
printf "Voici un texte sans retour a la ligne" | nc -q 0 localhost $1
sleep 0.2
echo -n "This is a text without backline at the end" | nc -q 0 localhost $1
sleep 0.4
printf "Et voici un texte avec plusieurs\nretours\na\nla\nligne\n" | nc -q 0 localhost $1
sleep 0.2

bash test_eof.sh $1
sleep 1

cat very_long_msg.txt | nc -q 0 localhost $1

sleep 1

cat other_long_msg.txt | nc -q 0 localhost $1

sleep 2

killall final
killall nc

# removed it because it seems that it doesn't work. use killall work like a charm :>
#kill $PID
#kill $PID2

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
