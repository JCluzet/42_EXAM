# check if there is connexion to the internet, else do git pull for maj
if ! ping -c 1 google.com > /dev/null 2>&1; then
    printf "42_EXAM: Demarrage hors connexion...\n\n"
    sleep 2
else
    git pull
fi