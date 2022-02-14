# check if there is connexion to the internet, else do git pull for maj
if ! ping -c 1 google.com > /dev/null 2>&1; then
    echo "42_EXAM: Demarrage hors connexion...\n\n"
else
    git pull
fi