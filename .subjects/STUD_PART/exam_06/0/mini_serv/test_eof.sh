if [ $(uname) == "Darwin" ]; then
	nc_command="nc localhost $1"
else
	nc_command="nc -q 0 localhost $1"
fi

for x in `cat eof_test`; do
  printf $x
  sleep 0.1
done | eval $nc_command
