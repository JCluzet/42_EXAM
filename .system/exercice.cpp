#include "exam.hpp"

exercice::exercice(void) {
    this->name = "UNKNOWN";
    assignement = 0;
    level_ex = 0;
    time_bef_grade = time(NULL);
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
    start_new_ex();
    return (0);
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
    system("mkdir rendu 2> /dev/null");
    system("mkdir subjects 2> /dev/null");
    system("mkdir .system/grading 2> /dev/null");

    // copy all the files in the current get_path() + attachement/* to the subjects directory
    std::string cmd_system_call = "cp -r " + get_path() + "/attachement/*" + " subjects/";
    system(cmd_system_call.c_str());

    // copy all the files in the current get_path() without the attachement folder to the .system/grading/ directory
    cmd_system_call = "cp " + get_path() + "* .system/grading/ >/dev/null 2>&1";
    system(cmd_system_call.c_str());

    return (false);
}

// ==> Randomize exercice (give 1 into list)
exercice *randomize_exercice(std::map<int, exercice> list, bool remove_success)
{
    // if setting_dse is 1, remove all exercice in list having a name in .system/exam_token/success_ex 
    if (remove_success == 0)
    {
        std::ifstream success_ex("success/success_ex");
        std::string line;
        std::string name;
        int assignement;
        int level_ex;
        int time_bef_grade;
        while (std::getline(success_ex, line))
        {
            std::istringstream iss(line);
            iss >> name;
            for (std::map<int, exercice>::iterator it = list.begin(); it != list.end(); it++)
            {
                if (it->second.get_name() == name)
                {
                    list.erase(it);
                    break;
                }
            }
        }
        success_ex.close();
    }


    // Check if there is still exercice in the list
    std::map<int, exercice>::iterator it = list.begin();
    if (list.size() == 0)
    {
        std::cout << "Error: all exercices for this level have been done" << std::endl;
        std::cout << "Please set to" << RED << BOLD << " OFF " << RESET << "option 1 in settings." << std::endl;
        std::cout << "Or edit/delete your success/success_ex file" << std::endl;
        std::cout << "Then relaunch 42_EXAM and recover your exam" << std::endl;
        exit(0);
    }
    srand(time(NULL));
    int random = rand() % list.size();
    for (int i = 0; i < random; i++)
        it++;
    return (&it->second);
}

exercice::exercice(int level, std::string ex_name) {
    this->name = ex_name;
    level_ex = level;
    assignement = 0;
    time_bef_grade = time(NULL);
}

exercice::exercice(int level, std::string ex_name, int assign, time_t tbg) {
    this->name = ex_name;
    level_ex = level;
    assignement = assign;
    time_bef_grade = tbg;
}

exercice::exercice(exercice const & src) {
    this->name = src.name;
    level_ex = src.level_ex;
    assignement = src.assignement;
    time_bef_grade = src.time_bef_grade;
}

exercice::~exercice(void) {
}

exercice&  exercice::operator=(exercice const & src) {
    this->name = src.name;
    level_ex = src.level_ex;
    assignement = src.assignement;
    time_bef_grade = src.time_bef_grade;
    return (*this);
}


// ==> GETTER/SETTER
void exercice::set_time_bef_grade(time_t time)
{
    time_bef_grade = time;
}

std::string exercice::get_name(void) {
    return (this->name);
}

void exercice::reset_assignement(void)
{
    assignement = 0;
}

void exercice::up_assignement(void) {
    this->assignement++;
}

int exercice::get_lvl(void) {
    return (this->level_ex);
}

void exercice::up_lvl(void) {
    level_ex++;
}

int exercice::get_assignement(void) {
    return (this->assignement);
}

void exercice::set_assignement(int assignement) {
    this->assignement = assignement;
}