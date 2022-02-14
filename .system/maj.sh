output=$(git pull | grep "Could not resolve" | wc -l)
if [ $output == "1" ]
then
    echo "42_EXAM: Demarrage hors connexion...\n\n"
    sleep 2
    exit 1
fi