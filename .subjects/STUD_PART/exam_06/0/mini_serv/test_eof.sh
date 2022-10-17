for x in `cat eof_test`; do
  printf $x
  sleep 0.1
done | nc localhost $1
