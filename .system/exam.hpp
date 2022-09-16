#pragma once

#include "exercice.hpp"
#include <iostream>
#include <map>

// include for readline
#include <readline/readline.h>
#include <readline/history.h>

#include <signal.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <iomanip>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"
#define CYAN "\e[36m"
#define UNDERLINE "\e[4m"
#define WHITE "\e[97m"
#define LIME "\e[92m"
#define RED "\e[91m"
#define MAGENTA "\e[95m"
#define YELLOW "\e[93m"
#define REMOVE_LINE "\e[1A\e[K"

std::string current_path(void);
std::string remaining_time(time_t end_time);
std::string lastupdate(time_t end_time);
std::string remaining_time(time_t end_time);
std::string current_path(void);
exercice *randomize_exercice(std::map<int, exercice> list, bool remove_success);
exam restore_data(void);
bool file_exists(std::string path);

void reset_folder(void);
void connexion(void);
void sigc(int sig);
void sigd(void);
void sigd(void);

int stud_or_swim(void);
int piscine_menu(void);
int stud_menu(void);

class exam
{
public:
    exam(void);
    exam(exam const &src);
    exam(bool t);
    ~exam(void);
    void info(void);
    void ask_param(void);
    void fail_ex(void);
    void success_ex(void);
    void explanation(void);
    int get_exam_number(void);
    int get_lvl(void);
    void store_data();
    void up_lvl(void);
    void exam_help();
    std::string get_path(void);
    time_t get_end_time(void);
    time_t get_start_time(void);
    void infovip(void);
    int change_ex(void);
    void exam_prompt(void);
    bool prepare_current_ex(void);
    bool clean_all(void);
    void restore_data(void);
    bool start_new_ex(void);
    exam &operator=(exam const &src);
    std::map<int, exercice> list_dir();

    std::map<int, exercice> list_ex_lvl;

    std::map<int, exercice> lvl_ex;
    exercice *current_ex;
    bool student;
    bool waiting_time;
    int level_max;
    bool changex;

private:
    void set_max_time(void);
    void grademe(void);
    void settings_menu(void);
    void grade_request(bool i);
    void exam_random_show(void);
    void end_exam(void);
    void set_max_lvl(void);
    int stud_menu(void);
    void load_settings(void);
    void save_settings(void);
    int piscine_menu(void);
    int stud_or_swim(void);

    bool setting_dse;
    bool setting_dcc;
    std::string username;
    bool connexion_need;

    time_t start_time;
    time_t end_time;

    bool reelmode;
    int level_per_ex_save;
    int time_max;
    int exam_number;
    int using_cheatcode;
    int exam_grade;
    bool vip;
    int level_per_ex;
    int level;
    int failures;
    bool backup;
};