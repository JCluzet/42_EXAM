#include "exam.hpp"

exercice::exercice(void) {
    this->name = "UNKNOWN";
    assignement = 0;
    level_ex = 0;
    time_bef_grade = time(NULL);
}

// ==> Randomize exercice (give 1 into list)
exercice *randomize_exercice(std::map<int, exercice> list)
{
    std::map<int, exercice>::iterator it = list.begin();
    if (list.size() == 0)
    {
        std::cout << "Error: no exercice in the list" << std::endl;
        exit(1);
    }
    srand(time(NULL));
    int random = rand() % list.size();
    for (int i = 0; i < random; i++)
        it++;
    return (&it->second);
}

// ==> Return the minutes to wait relative to assignement number
double exercice::grade_time(void)
{
    // do a vector contain all the fibonnaci numbers
    std::vector<double> fib;
    if(get_assignement() == 0 )
        return (0);
    fib.push_back(0.5);
    fib.push_back(2.5);
    for (int i = 2; i < 100; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        if(i - 2 == get_assignement() - 1)
            return(fib[i - 2]);
    }
    return(0);
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