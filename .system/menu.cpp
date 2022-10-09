#include "exam.hpp"

// ==> Animation of exercice name
void exam::exam_random_show(void)
{
    int pot_pts;
    if (level == 0)
        pot_pts = 0;
    else
        pot_pts = level_per_ex;
    std::map<int, exercice>::iterator it = list_ex_lvl.begin();
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << pot_pts << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
    double time = 100000;
    for (int i = 0; i < 20; i++)
    {
        std::cout << REMOVE_LINE;
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << pot_pts << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
        it++;
        if (it == list_ex_lvl.end())
            it = list_ex_lvl.begin();
        if (list_ex_lvl.size() == 1)
            break;
        usleep(time);
        time += 10000;
    }
    std::cout << REMOVE_LINE;
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << pot_pts << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
    if (level_per_ex != 100)
    {
        for (int i = 0; i < level_per_ex && level == 0; i++)
        {
            std::cout << REMOVE_LINE;
            std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << i << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
            usleep(40000);
        }
    }
    std::cout << REMOVE_LINE;
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << (int)level_per_ex << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
}

// ==> Help section
void exam::exam_help()
{
    std::cout << "Commands:" << std::endl;
    std::cout << LIME << "    help:" << RESET << " display this help" << std::endl;
    std::cout << LIME << "    settings: " << RESET << "display settings menu" << std::endl;
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
        std::cout << LIME << "    new_ex:" << RESET << " generate a new exercice for the same level" << std::endl;
    }
}

// ==> display of exam status
void exam::info(void)
{
    // std::cout << "⚠️  V2 of 42_EXAM was release " << lastupdate(time(0)) << " ago." << std::endl << "If you encounter any problems, please report them on the Github repo."<< std::endl << std::endl;
    // std::cout << "==================================================================" << std::endl;
    // std::cout << "Level: " << LIME << level << RESET << " ";
    if (reelmode)
        std::cout << "Mode: " << MAGENTA << "REAL" << RESET << " | ";
    else
        std::cout << "Mode: " << YELLOW << "TEST" << RESET << " (Your grade will not be counted)" << std::endl;
    std::cout << "Current Grade: " << LIME << level_per_ex_save * level << RESET << " / 100" << std::endl;
    // std::cout << "Assignments: " << std::endl;
    std::cout << std::endl;

    for (std::map<int, exercice>::iterator it = lvl_ex.begin(); it != lvl_ex.end(); it++)
    {
        std::cout << "  Level " << LIME << it->second.get_lvl() << RESET << ": " << std::endl;
        for (unsigned int i = 0; i < it->second.get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " potential points (" << RED << "Failure" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << it->second.get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " potential points (" << LIME << "Success" << RESET << ")" << std::endl;
    }

    std::cout << "  Level " << LIME << level << RESET << ": " << std::endl;
    if (current_ex->get_assignement() == 0 && backup == 0 && !changex)
        exam_random_show();
    else
    {
        for (unsigned int i = 0; i < current_ex->get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << (int)(((double)level + 1) / (double)level_max * 100) << " potential points (" << RED << "Failure" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << (int)(((double)level + 1) / (double)level_max * 100) << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
    }
    std::cout << std::endl
              << "Assignement: " << LIME << current_ex->get_name() << RESET << " for " << LIME << BOLD << (double)(((double)level + 1) / (double)level_max * 100) << RESET << "xp" <<RESET << ", ";
    std::cout << "try: " << YELLOW << current_ex->get_assignement() << RESET << std::endl << std::endl;
    std::cout << "Subject location:  " << LIME << current_path() << "/subjects/subject.en.txt" << RESET << std::endl;
    std::cout << "Exercice location: " << RED << current_path() << "/rendu/" << current_ex->get_name() << "/" << RESET << std::endl;
    std::cout << "Here you " << RED << BOLD << "don't need" << RESET <<" to use git." << std::endl
              << std::endl;
    std::cout << "End date: " << LIME << std::put_time(std::localtime(&end_time), "%d/%m/%Y %H:%M:%S") << RESET << std::endl;
    std::cout << "Left time: " << LIME << remaining_time(end_time) << RESET << std::endl;
    std::cout << std::endl
              << "==================================================================" << std::endl;
    std::cout << "Use the \"" << LIME << "grademe" << RESET << "\" command to be graded, or \"" << LIME << "help" << RESET << "\" to get some help." << std::endl;
    backup = 1;
}

void exam::infovip(void)
{
    std::cout << "==================================================================" << std::endl;
    std::cout << "You are currently at level " << LIME << level << RESET << std::endl;
    if (reelmode)
        std::cout << "You are running in " << MAGENTA << "REAL" << RESET << " mode (Your grade will be counted)" << std::endl;
    else
        std::cout << "You are running in " << YELLOW << "TEST" << RESET << " mode (Your grade will not be counted)" << std::endl;
    std::cout << "Your current grade is " << LIME << level_per_ex_save * level << RESET << "/100" << std::endl;
    std::cout << "Assignments: " << std::endl;

    for (std::map<int, exercice>::iterator it = lvl_ex.begin(); it != lvl_ex.end(); it++)
    {
        std::cout << "  Level " << LIME << it->second.get_lvl() << RESET << ": " << std::endl;
        for (unsigned int i = 0; i < it->second.get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " potential points (" << RED << "Failure" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << it->second.get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " for " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " potential points (" << LIME << "Success" << RESET << ")" << std::endl;
    }

    std::cout << "  Level " << LIME << level << RESET << ": " << std::endl;
    if (current_ex->get_assignement() == 0 && backup == 0 && !changex)
        exam_random_show();
    else
    {
        for (unsigned int i = 0; i < current_ex->get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << (int)(((double)level + 1) / (double)level_max * 100) << " potential points (" << RED << "Failure" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " for " << (int)(((double)level + 1) / (double)level_max * 100) << " potential points (" << CYAN << "Current" << RESET << ")" << std::endl;
    }

    std::cout << std::endl
              << "Your current assignement is " << LIME << current_ex->get_name() << RESET << " for " << LIME << (int)(((double)level + 1) / (double)level_max * 100) << RESET << " potential points" << std::endl;
    std::cout << "It is assignement " << YELLOW << current_ex->get_assignement() << RESET << " for level " << LIME << level << RESET << std::endl;
    std::cout << "The subject is located at: " << LIME << current_path() << "/subjects/subject.en.txt" << RESET << std::endl;
    std::cout << "You must turn in your files in a subdirectory with the" << std::endl;
    std::cout << "same name as the assignement (" << RED << current_path() << "/rendu/" << current_ex->get_name() << RESET << "/)." << std::endl;
    std::cout << "Here you don't need to use git." << std::endl
              << std::endl;
    std::cout << "The end date for this exam is: " << LIME << std::put_time(std::localtime(&end_time), "%d/%m/%Y %H:%M:%S") << RESET << std::endl;
    std::cout << "You have " << LIME << remaining_time(end_time) << RESET << " remaining" << std::endl;
    std::cout << std::endl
              << "=============================================================================" << std::endl;
    std::cout << "You can work on your assignement. When you are sure you're done with it," << std::endl;
    std::cout << "use the \"" << LIME << "grademe" << RESET << "\" command to be graded, or \"" << LIME << "help" << RESET << "\" to get some help." << std::endl;
}

// ==> display connexion animation
void connexion(void)
{
    system("clear");
    std::cout << RESET;
    std::string examsystem = "examshell";
    for (int i = 0; i < examsystem.length(); i++)
    {
        std::cout << examsystem[i];
        usleep(70000);
        fflush(stdout);
    }
    std::cout << std::endl;
    usleep(600000);
    system("clear");
    std::cout << BOLD << UNDERLINE << "ExamShell v2.1" << RESET << std::endl
              << std::endl;
    std::cout << BOLD << "login:" << RESET;
    fflush(stdout);
    usleep(600000);
    std::string login = getenv("USER");
    for (int i = 0; i < login.size(); i++)
    {
        usleep(100000);
        std::cout << login[i];
        fflush(stdout);
    }

    usleep(400000);
    std::cout << std::endl
              << BOLD << "password:" << RESET;
    fflush(stdout);
    srand(time(NULL));
    int password_size = rand() % 10 + 4;
    for (int i = 0; i < password_size; i++)
    {
        usleep(150000);
        std::cout << "*";
        fflush(stdout);
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
    // usleep(200000);
}

// ==> First menu display
int exam::stud_or_swim(void)
{
    std::string choice = "";
    while (choice != "1" && choice != "2")
    {
        system("clear");
        std::cout << WHITE << BOLD << "         42EXAM " << std::endl;
        if(vip)
            std::cout << "    You are a " << LIME << "VIP" << WHITE << BOLD << " user" << RESET << std::endl << std::endl;
        else
            std::cout << "     Made by " << LIME << "jcluzet" << RESET << std::endl
                  << std::endl
                  << std::endl;
        std::cout << LIME << BOLD << "            1" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |  Piscine PART  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl;
        std::cout << LIME << BOLD << "            2" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |  Student PART  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl << std::endl;

        std::cout << LIME << BOLD << "            3" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |" << RESET << BOLD << "  SETTINGS PART " << WHITE << BOLD << "|" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << std::endl;
        
        if (choice == "-1")
            std::cout << BOLD << RED;
        else 
            std::cout << WHITE << BOLD;
        std::cout << "    Enter your choice:" << RESET << std::endl
                  << "            ";
        // std::cin >> choice;
        if (!std::getline(std::cin, choice))
            sigd();
        if (choice == "3")
        {
            settings_menu();
            std::cin.ignore();
        }
        else if (choice != "1" && choice != "2" )
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}

// ==> Setting MENU
void exam::settings_menu(void)
{
    std::string input = "";
    while (input != "0")
    {
    save_settings();
    system("clear");
    std::cout << WHITE << BOLD << "     === SETTINGS MENU ===" << std::endl << RED << "          BACK" << RESET << WHITE << BOLD << " with " << RED << "0" << RESET << std::endl << std::endl;

    std::cout << LIME << "1." << WHITE << BOLD << " Enable exercices you already passed";
    if (setting_dse)
        std::cout << LIME << BOLD << " ON" << RESET << std::endl;
    else
        std::cout << RED << BOLD << " OFF" << RESET << std::endl;

    std::cout << LIME << "2." << WHITE << BOLD << " Enable cheat commands";
    if (setting_dcc)
        std::cout << LIME << BOLD << " ON" << RESET << std::endl;
    else
        std::cout << RED << BOLD << " OFF" << RESET << std::endl;
    std::cin >> input;
    if (input == "1")
    {
        setting_dse = !setting_dse;
    }
    if (input == "2")
        setting_dcc = !setting_dcc;
    }
    std::cout << REMOVE_LINE << RESET << WHITE << BOLD << "Save settings..." << std::endl;
    std::string tmp = "bash .system/data_sender.sh \"settings_out:enable_ead>" + std::to_string(setting_dse);
    tmp += "__settings:enable_cheat>" + std::to_string(setting_dcc) + "\"";
    system(tmp.c_str());
}

// ==> Display the menu for the student part
int exam::stud_menu(void)
{
    std::string choice = "-2";
    while (choice == "-1" || choice == "-2")
    {
        system("clear");
        std::cout << WHITE << BOLD << "         42EXAM " << std::endl
                  << RED << "   BACK" << RESET << WHITE << BOLD << " to menu with " << RED << "0" << RESET << std::endl;
        std::cout << LIME << BOLD << "            " << RESET << std::endl
                  << std::endl
                  << std::endl;
        std::cout << WHITE << BOLD << "    |  Piscine PART  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << LIME << "            •           " << std::endl;
        std::cout << WHITE << BOLD << "    |  Student PART  |" << std::endl;
        std::cout << std::endl
                  << LIME << "            2" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM RANK 02" << std::endl;
        std::cout << std::endl
                  << LIME << "            3" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM RANK 03" << std::endl;
        std::cout << std::endl
                  << LIME << "            4" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM RANK 04" << std::endl;
        std::cout << std::endl
                  << LIME << "            5" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM RANK 05" << std::endl;
        std::cout << std::endl
                  << LIME << "            6" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM RANK 06";
        std::cout << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl;
        if (choice == "-1")
            std::cout << BOLD << RED;
        std::cout << std::endl
                  << std::endl;
        std::cout << "    Enter your choice:" << RESET << std::endl
                  << "            ";
        if (!std::getline(std::cin, choice))
            sigd();

        if (choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "0")
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}

// ==> Display the menu for the piscine part
int exam::piscine_menu(void)
{
    std::string choice = "-2";
    while (choice == "-1" || choice == "-2")
    {
        system("clear");
        std::cout << WHITE << BOLD << "         42EXAM " << std::endl
                  << RED << "   BACK" << RESET << WHITE << BOLD << " to menu with " << RED << "0" << RESET << std::endl;
        std::cout << LIME << BOLD << "            " << RESET << std::endl
                  << std::endl
                  << LIME << "            •           " << std::endl
                  << WHITE << BOLD << "    |  Piscine PART  |" << std::endl;
        std::cout << std::endl
                  << LIME << "            1" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM WEEK 01" << std::endl;
        std::cout << std::endl
                  << LIME << "            2" << RESET << WHITE << BOLD << std::endl
                  << "       EXAM WEEK 02" << std::endl;
        std::cout << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << std::endl;
        std::cout << WHITE << BOLD << "    |  Student PART  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl;
        if (choice == "-1")
            std::cout << BOLD << RED;
        std::cout << std::endl;
        std::cout << "    Enter your choice:" << RESET << std::endl
                  << "            ";
        if (!std::getline(std::cin, choice))
            sigd();
        if (choice != "1" && choice != "2" && choice != "0")
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}