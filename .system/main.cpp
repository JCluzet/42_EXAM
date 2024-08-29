#include "exam.hpp"

// ==> CGV Acceptation

void CGVAcceptation(void)
{
    system("clear");
    std::cout << BOLD << WHITE;
    std::cout << "You must accept these rules to use this program:" << std::endl
              << std::endl;
    std::cout << RESET;
    std::ifstream file(".system/CGV.txt");
    std::string line;
    while (std::getline(file, line))
        std::cout << line << std::endl;

    std::cout << BOLD << WHITE << std::endl;
    std::cout << RESET;
    std::string input;
    std::getline(std::cin, input);
    if (input != "agree")
    {
        std::cout << "You must accept these rules to use this program." << std::endl;
        exit(0);
    }
    else
    {
        std::ofstream file(".system/acceptCGV");
        file << "1";
        file.close();
        // thanks for accepting
        std::cout << "Thanks for accepting theses rules, and good luck for your exam!" << std::endl;
        sleep(2);
    }
}

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
        while (input.back() == ' ')
            input.pop_back();
        while (input.front() == ' ')
            input.erase(input.begin());
        if (input.empty())
            continue;
        add_history(input.c_str());
        if ((input == "remove_grade_time" || input == "new_ex" || input == "force_success") && !setting_dcc)
            std::cout << " ❌ Cheat commands are currently disabled, use " << LIME << BOLD << "settings" << RESET << " command." << std::endl;
        else if (input == "finish" || input == "exit" || input == "quit")
        {
            std::cout << "Are you sure you want to" << RED << " exit" << RESET << " the exam?" << std::endl;
            std::cout << "All your progress will be " << RED << "lost" << RESET << "." << std::endl;
            std::cout << "Type " << LIME << BOLD << "yes" << RESET << " to confirm." << std::endl;
            // read input
            std::string input;
            std::getline(std::cin, input);
            if (input == "yes")
            {
                if (std::ifstream(".system/exam_token/actuel_token.txt"))
                    remove(".system/exam_token/actuel_token.txt");
                exit(0);
            }
            else
                std::cout << " ** Abort ** " << std::endl;
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
            if (!vip)
            {
                std::cout << "'force_success' is a Grademe+ command, contribute by making a Pull Request or support with command 'sponsor'" << std::endl;
            }
            else
            {
                using_cheatcode++;
                success_ex(1);
            }
        }
        else if (input == "help")
        {
            exam_help();
        }
        else if (input == "sponsor")
        {
            std::cout << "\n\e[1m\e[96mA word from the creator:\e[0m\n"
                      << std::endl;
            std::cout << "This program has been created entirely \e[92mfor free\e[0m and \e[92mopen-source\e[0m.\n";
            std::cout << "The VIP option exists not to create a business, but simply to help\n"
                      << "those who enjoy using the program and have a little extra to give.\n" << std::endl;
            std::cout << "If you're a student who loves this tool and wants to support my journey,\n"
                      << "consider becoming a VIP by making a small donation.\n";
            std::cout << "However, if you prefer to contribute without spending money, \e[95myou can\n"
                      << "always help out by making a Pull Request\e[0m. I would welcome your support\n"
                      << "with open arms.\n" << std::endl;
            std::cout << "For those who are just starting out, or can't contribute financially,\n"
                      << "you can also \e[95memail me\e[0m explaining why you'd like VIP status, and I'll\n"
                      << "be happy to grant it to you.\n" << std::endl;
            std::cout << "The VIP status does not limit the program's core features. It simply\n"
                      << "offers two small additional options for those who wish to support the project.\n" << std::endl;
            std::cout << "\e[1mThank you for your support, and happy coding! ♥︎\e[0m\n" << std::endl;
            std::cout << "Press any key to open the sponsor page..." << std::endl;
            std::cin.get();


            if (is_linux)
                std::system("xdg-open http://sponsor.grademe.fr");
            else
                std::system("open http://sponsor.grademe.fr");
            system("clear");
            std::cout << "Thanks a lot ♥︎" << std::endl << std::endl;
            if (vip)
                infovip();
            else
                info();

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
        // info();
    }
}
// jo je taime

// ==> Starting a new exercise/exam
bool exam::start_new_ex(void)
{
    load_settings();
    if (!backup)
    {
        list_ex_lvl = list_dir();
        exercise ex = *randomize_exercise(list_ex_lvl, setting_dse);
        current_ex = new exercise(ex);
        prepare_current_ex();
        store_data();
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

    if (file_exists("a.out"))
        remove("a.out");

    exam exm;

    // Adding CGV Acceptation
    if (!file_exists(".system/acceptCGV"))
        CGVAcceptation();

    if (file_exists(".system/exam_token/current_token.txt"))
        exm.restore_data();
    else
        exm.ask_param();

    exm.start_new_ex();

    return (0);
}