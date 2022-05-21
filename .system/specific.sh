# remove all in the folder in the first argument except the file in the second argument
for file in `ls $1`
do
    if [ "$file" != "$2" ]
    then
        rm -r $1/$file
    fi
done