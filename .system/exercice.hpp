#pragma once
#include <iostream>

class exam;

class exercice
{
    public:
        exercice(void);
        exercice(int level, std::string ex_name);
        exercice(int level, std::string ex_name, int assign, time_t tbg);
        exercice(exercice const & src);
        ~exercice(void);

        exercice&     operator=(exercice const & src);
        std::string get_name(void);
        int get_assignement(void);
        void reset_assignement(void);
        void up_assignement(void);
        void set_assignement(int assignement);
        void up_lvl(void);
        double grade_time(void);
        void set_time_bef_grade(time_t time_bef_grade);
        int get_lvl(void);
        time_t time_bef_grade;
    private :
        int assignement;
        std::string name;
        int level_ex;
};