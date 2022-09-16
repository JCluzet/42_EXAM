#include "exam.hpp"

// ==> Shell prompt
void exam::exam_prompt(void)
{
    std::string input;
    int is_linux = 0;
#ifdef __linux__
    is_linux = 1;
#endif

    while (1)
    {
        char *line = readline("\e[93mexamshell\e[0m> ");
        if (line == NULL)
            sigd();
        input = line;
        if ((input == "remove_grade_time" || input == "new_ex" || input == "force_success") && !setting_dcc)
            std::cout << " ❌ Cheat commands are currently disabled, use " << LIME << BOLD << "settings" << RESET << " command." << std::endl;
        else if (input == "finish" || input == "exit" || input == "quit")
        {
            if (std::ifstream(".system/exam_token/actuel_token.txt"))
                remove(".system/exam_token/actuel_token.txt");
            exit(0);
        }
        else if (input == "settings")
        {
            changex = 1;
            settings_menu();
            if (vip)
                infovip();
            else
                info();
        }
        else if (input == "grademe")
        {
            grademe();
        }
        else if (input == "status")
        {
            changex = 1;
            if (vip)
                infovip();
            else
                info();
        }
        else if (input == "new_ex")
        {
            change_ex();
            using_cheatcode++;
        }
        else if (input == "force_success")
        {
            using_cheatcode++;
            std::string tmp = "bash .system/data_sender.sh \"cheatcode:force_success\"";
            system(tmp.c_str());
            success_ex();
        }
        else if (input == "help")
        {
            exam_help();
        }
        else if (input == "repo_git")
        {
            std::string tmp = "bash .system/data_sender.sh \"cheatcode:repo_git\"";
            system(tmp.c_str());
            std::cout << "Opening git repo..." << std::endl;
            if (is_linux)
                std::system("xdg-open http://git.grademe.fr");
            else
                std::system("open http://git.grademe.fr");
        }
        else if (input == "remove_grade_time")
        {
            std::string tmp = "bash .system/data_sender.sh \"cheatcode:remove_grade_time\"";
            system(tmp.c_str());
            std::cout << "Time between grading is now removed for this exam" << std::endl;
            waiting_time = false;
            using_cheatcode++;
        }
        else if (input == "gradenow" && vip)
        {
            grade_request(1);
        }
        else if (input == "")
            std::cout << REMOVE_LINE;
        else if (input != "")
            std::cout << "           **Unknown command**     type " << LIME << "help" << RESET << " for more help" << std::endl;
        if (input != "")
            add_history(line);
        // info();
    }
}
// jo je taime

// ==> Starting a new exercice/exam
bool exam::start_new_ex(void)
{
    std::string enter;
    load_settings();
    if (!backup)
    {
        if (connexion_need)
            connexion();
        list_ex_lvl = list_dir();
        exercice ex = *randomize_exercice(list_ex_lvl, setting_dse);
        current_ex = new exercice(ex);
        prepare_current_ex();
        store_data();
    }
    if (connexion_need)
    {
        std::cout << "You're connected " << LIME << username << RESET << "!" << std::endl;
        std::cout << "You can log out at any time. If this program tells you you earned points,\nthen they will be counted whatever happens.\n"
                  << std::endl;
        std::cout << BOLD << WHITE << "You are about to start the project " << LIME << BOLD << "ExamRank0" << exam_number << BOLD << WHITE << ", in " << MAGENTA << "REAL" << BOLD << WHITE << " mode, at level " << YELLOW << level << BOLD << WHITE << "." << RESET << std::endl;
        std::cout << WHITE << BOLD << "You would have " << LIME << BOLD << (time_max / 60) << "hrs " << BOLD << WHITE << "to complete this project." << RESET << std::endl
                  << "Press a key to start exam 🏁" << std::endl;
        if (!std::getline(std::cin, enter))
            sigd();
        connexion_need = false;
    }
    if (vip)
        infovip();
    else
        info();
    exam_prompt();
    return (true);
}

int main(int argc, char **argv)
{
    signal(SIGINT, sigc);
    signal(SIGQUIT, sigc);
    signal(SIGTERM, sigc);

    // check_readline();

    if (file_exists("a.out"))
        remove("a.out");

    exam exm;

    if (file_exists(".system/exam_token/actuel_token.txt"))
        exm.restore_data();
    else
        exm.ask_param();

    exm.start_new_ex();

    return (0);
}