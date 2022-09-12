#include "exam.hpp"

// ==> Help section
void exam::exam_help()
{
    std::cout << "Commands:" << std::endl;
    std::cout << LIME << "    help:" << RESET << " display this help" << std::endl;
    std::cout << LIME << "    status:" << RESET << " display information about the exam" << std::endl;
    std::cout << LIME << "    finish:" << RESET << " exit the exam" << std::endl;
    std::cout << LIME << "    grademe:" << RESET << " grade your exercice" << std::endl;
    std::cout << LIME << "    repo_git:" << RESET << " visit github repo" << std::endl;
    std::cout << "See github repo to find some more 'cheat' command" << std::endl;
    if (vip)
    {
        std::cout << BOLD << LIME << "VIP MENU:" << RESET << std::endl;
        std::cout << LIME << "    force_success:" << RESET << " force a ex to success" << std::endl;
        std::cout << LIME << "    remove_grade_time:" << RESET << " remove grade time limit between two grademe" << std::endl;
        std::cout << LIME << "    gradenow:" << RESET << " instant grade exercice" << std::endl;
    }
}

// include for readline
#include <readline/readline.h>
#include <readline/history.h>

// ==> Shell prompt
void exam::exam_prompt(void)
{
    std::string input;
    int is_linux = 0;
    #ifdef __linux__
        is_linux = 1;
    #endif

    while(1)
    {
    char *line = readline("\e[93mexamshell\e[0m> ");
    if (line == NULL)
        sigd();
    input = line;
    if (input == "remove_grade_time" || input == "new_ex" || input == "force_success" && !setting_dcc)
        std::cout << "Cheat commands are currently disabled, use " << LIME << BOLD << "settings" << RESET << " command." << std::endl;
    else if (input == "finish" || input == "exit" || input == "quit")
    {
        if (std::ifstream(".system/exam_token/actuel_token.txt"))
            remove(".system/exam_token/actuel_token.txt");
        exit(0);
    }
    else if (input == "settings")
    {
        add_history(line);
        changex = 1;
        settings_menu();
        if(vip)
            infovip();
        else
            info();
    }
    else if (input == "grademe")
    {
        add_history(line);
        grademe();
    }
    else if (input == "status")
    {
        add_history(line);
        changex = 1;
        if(vip)
            infovip();
        else
            info();
    }
    else if (input == "new_ex")
    {
        add_history(line);
        change_ex();
    }
    else if (input == "force_success")
    {
        add_history(line);
        std::string tmp = "bash .system/data_sender.sh \"cheatcode:force_success\"";
        system(tmp.c_str());
        success_ex();
    }
    else if (input == "help")
    {
        add_history(line);
        exam_help();
    }
    else if (input == "repo_git")
    {
        add_history(line);
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
        add_history(line);
        std::string tmp = "bash .system/data_sender.sh \"cheatcode:remove_grade_time\"";
        system(tmp.c_str());
        std::cout << "Time between grading is now removed for this exam" << std::endl;
        waiting_time = false;
    }
    else if (input == "gradenow" && vip)
    {
        add_history(line);
        grade_request(1);
    }
    else if (input == "")
        std::cout << REMOVE_LINE;
    else if (input != "")
        std::cout << "           **Unknown command**     type " << LIME << "help" << RESET << " for more help" << std::endl;
    // info();
    }
}

// ==> Set good folder and copy subjects, etc...
bool exam::prepare_current_ex(void)
{
    if (level == level_max)
    {
        std::cout << "You have reached the maximum level of this exam." << std::endl;
        return (false);
    }
    if (!file_exists(get_path()))
    {
        std::cout << "Error: Cannot load exercice, unable to find valid path" << std::endl;
        return (false);
    }

    // clean all old files
    clean_all();

    // create directory for the current exercice
    system("mkdir rendu && mkdir subjects && mkdir .system/grading");

    // copy all the files in the current get_path() + attachement/* to the subjects directory
    std::string cmd_system_call = "cp -r " + get_path() + "/attachement/*" + " subjects/";
    system(cmd_system_call.c_str());

    // copy all the files in the current get_path() without the attachement folder to the .system/grading/ directory
    cmd_system_call = "cp " + get_path() + "* .system/grading/ >/dev/null 2>&1";
    system(cmd_system_call.c_str());

    return (false);
}
// jo je taime

// ==> Starting a new exercice/exam
bool exam::start_new_exam(void)
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
    if(connexion_need)
    {
        std::cout << "You're connected " << LIME << username << RESET << "!" << std::endl;
        std::cout << "You can log out at any time. If this program tells you you earned points,\nthen they will be counted whatever happens.\n"
                  << std::endl;
        std::cout << BOLD << WHITE << "You are about to start the project " << LIME << BOLD << "ExamRank0" << exam_number << BOLD << WHITE << ", in " << MAGENTA << "REAL" << BOLD << WHITE << " mode, at level " << YELLOW << level << BOLD << WHITE << "." << RESET << std::endl;
        std::cout << WHITE << BOLD << "You would have " << LIME << BOLD << (time_max / 60) << "hrs " << BOLD << WHITE << "to complete this project." << RESET << std::endl << "Press a key to start exam 🏁" << std::endl;
        if (!std::getline(std::cin, enter))
            sigd();
        connexion_need = false;
    }
    if(vip)
        infovip();
    else
        info();
    exam_prompt();
    return (true);
}

// ==> Function to change exercice
int exam::change_ex(void)
{
    connexion_need = false;
    backup = false;
    // if there is only 1 exercice, we can't change it
    if (list_ex_lvl.size() == 1)
    {
        std::cout << "You can't change exercice, there is only one exercice in this level" << std::endl;
        return (0);
    }
    clean_all();
    system("clear");
    std::cout << "  > You have generated a new exercice" << std::endl;
    changex = 1;
    delete current_ex;
    start_new_exam();
    return (0);
}

void check_readline()
{
    // if readline is not installed
    int is_linux = 0;
    #ifdef __linux__
        is_linux = 1;
    #endif


    if (!file_exists("/usr/include/readline/readline.h") && is_linux)
    {
        std::cout << "Error: readline is not installed on your computer" << std::endl << std::endl;

        std::cout << "Auto install readline ? (y/n)" << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if (input == "y")
        {
            std::cout << "Installing readline..." << std::endl;
            system("sudo apt-get install libreadline-dev");
            std::cout << "Readline installed, please restart the program" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "Readline is required to use this program, please install it and restart the program" << std::endl;
            exit(0);
        }
        exit(0);
    }
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
    

    exm.start_new_exam();

    
    return (0);
}