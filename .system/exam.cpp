#include "exam.hpp"

// ==> Store all possible exercises in a map
std::map<int, exercise> exam::list_dir(void)
{
    struct dirent *entry;
    int i = 0;
    std::map<int, exercise> list;
    std::string path;
    if (student)
        path = ".subjects/STUD_PART/exam_0" + std::to_string(exam_number) + "/" + std::to_string(level) + "/";
    else
        path = ".subjects/PISCINE_PART/exam_0" + std::to_string(exam_number) + "/" + std::to_string(level) + "/";

    DIR *dir = opendir(path.c_str());
    std::string folder;
    if (dir == NULL)
    {
        std::cout << "Error: can't open directory" << get_path() << std::endl;
        sleep(100);
        return list;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        folder = entry->d_name;
        if (folder != "." && folder != ".." && folder != ".DS_Store")
        {
            list.insert(std::pair<int, exercise>(i, exercise(get_lvl(), folder)));
            i++;
        }
    }
    closedir(dir);
    return (list);
}

// ==> Get path of actual exercise
std::string exam::get_path(void)
{
    std::string path_exam;

    if (student)
        path_exam = ".subjects/STUD_PART/exam_0" + std::to_string(exam_number) + "/" + std::to_string(level) + "/" + current_ex->get_name() + "/";
    else
        path_exam = ".subjects/PISCINE_PART/exam_0" + std::to_string(exam_number) + "/" + std::to_string(level) + "/" + current_ex->get_name() + "/";
    return (path_exam);
}

// ==> Set max level for an exam
void exam::set_max_lvl(void)
{
    if (student)
    {
        if (exam_number == 2)
            level_max = 4;
        else if (exam_number == 3)
            level_max = 1;
        else if (exam_number == 4)
            level_max = 1;
        else if (exam_number == 5)
            level_max = 3;
        else if (exam_number == 6)
            level_max = 1;
    }
    else
        level_max = 8;
}

// ==> Set max hrs for exam (3 or 4)
void exam::set_max_time(void)
{
    if (student)
        time_max = 180;
    else
    {
        if (exam_number == 4)
            time_max = 480;
        else
            time_max = 240;
    }
}

void exam::explanation(void)
{
    std::string enter;
    system("clear");

    std::cout << std::endl
              << "\x1B[32m        EXPLANATION : \e[97m\e[1m" << std::endl
              << std::endl;
    std::cout << "     ⚠️  You have to work from a new window to keep this one \x1B[32mavailable\e[97m\e[1m\n"
              << std::endl;
    std::cout << "     📝 A random subject named \x1B[32msubject.en.txt\e[97m\e[1m will be generated" << std::endl;
    std::cout << "         > You must write your file (example.c) in the assign folder (see subject)," << std::endl;
    std::cout << "           this folder must be in folder: \x1B[32mrendu\e[97m\e[1m" << std::endl
              << std::endl;
    std::cout << "     🎓 Once completed, you can push/correct your project with : \x1B[32mgrademe\e[97m\e[1m" << std::endl;
    std::cout << "         If your level is validated, you move on to the next level 🎉" << std::endl;
    std::cout << "         If not, you have to start again ❌" << std::endl
              << std::endl;
    std::cout << "     ⌛️ Warning: The more you try to get the same project corrected, \n     the longer you will have to wait to get it \x1B[32mcorrected\e[97m\e[1m.\n\n"
              << std::endl;
    std::cout << "     📌 Nice reminder : Here you don't need to use GIT.\n         Remember that during the exam you will have to use it to push your project !\n\n"
              << std::endl
              << std::endl;

    std::cout << RED << "     ‼️  DICLAIMER" << WHITE << std::endl;
    std::cout << "         This program is " << RED << "not" << WHITE << " the real 42 exam and is " << RED << "not" << WHITE << " made by 42." << std::endl;
    std::cout << "         It is created by a student, free and open-source." << std::endl << std::endl;
    std::cout << RESET << "     (Press enter to continue...)" << std::endl
              << "      ";
    if (!std::getline(std::cin, enter))
        sigd();
}

// ==> First menu asking examrank number
void exam::ask_param(void)
{
    int select = 0;
    reset_folder();
    while (1)
    {
        exam_number = 0;
        while (exam_number == 0)
        {
            if (exam_number == 0)
                select = stud_or_swim();
            if (select == 1)
            {
                student = false;
                exam_number = piscine_menu();
            }
            else if (select == 2)
            {
                student = true;
                exam_number = stud_menu();
            }
        }
        std::cout << REMOVE_LINE << REMOVE_LINE << REMOVE_LINE << std::endl;
        if (student)
            std::cout << LIME << BOLD << "       EXAM RANK 0" << exam_number << RESET << std::endl;
        else
            std::cout << LIME << BOLD << "       EXAM WEEK 0" << exam_number << RESET << std::endl;
        std::cout << "   Confirm" << BOLD << WHITE << " Registration" << RESET << "?" << std::endl
                  << "          (y/n)" << std::endl
                  << "            ";
        std::string confirm;
        if (!std::getline(std::cin, confirm))
            sigd();
        if (confirm == "y" || confirm == "Y")
            break;
    }

    set_max_lvl();
    level_per_ex = ((double)level + 1) / (double)level_max * 100;
    level_per_ex_save = level_per_ex;

    // SEND DATA ABOUT CHOOSEN EXAM
    std::string tmp;
    std::string enter;
    if (student)
        tmp = "bash .system/data_sender.sh \"choose_examrank0" + std::to_string(exam_number) + "\"";
    else
        tmp = "bash .system/data_sender.sh \"choose_examweek0" + std::to_string(exam_number) + "\"";
    system(tmp.c_str());
    explanation();
    // =============================

    // CONNEXION ANIMATION
    connexion();
    set_max_time();
    std::cout << "You're connected " << LIME << username << RESET << "!" << std::endl;
    std::cout << "You can log out at any time. If this program tells you you earned points,\nthen they will be counted whatever happens.\n"
              << std::endl;
    std::cout << BOLD << WHITE << "You are about to start the project " << LIME << BOLD << "ExamRank0" << exam_number << BOLD << WHITE << ", in " << MAGENTA << "REAL" << BOLD << WHITE << " mode, at level " << YELLOW << level << BOLD << WHITE << "." << RESET << std::endl;
    std::cout << WHITE << BOLD << "You would have " << LIME << BOLD << (time_max / 60) << "hrs " << BOLD << WHITE << "to complete this project." << RESET << std::endl
              << "Press a key to start exam 🏁" << std::endl;
    if (!std::getline(std::cin, enter))
        sigd();
    // ====================

    // TIME SETUP
    start_time = time(0);
    end_time = start_time + (60 * time_max);
    struct tm temp;
    memset(&temp, '\0', sizeof(struct tm));
    localtime_r(&end_time, &temp);
    // ============

}

// CONSTRUCTOR/OPERATOR/GETTER/SETTER
exam::exam(void) : exam_grade(0), level(0), level_max(0), failures(0), student(false), backup(false), using_cheatcode(0)
{
    reelmode = true;
    waiting_time = true;
	vip = 0;
    username = getenv("USER");
    load_settings();
	system("curl https://user.grademe.fr/vip_list > .system/vip_list 2> /dev/null");
	std::ifstream vip_list(".system/vip_list");
	std::string line;

	while (std::getline(vip_list, line))
	{
		if (line == username)
		{
			vip = 1;
			break;
		}
	}
    changex = 0;
    system("rm .system/vip_list");
}

exam &exam::operator=(exam const &src)
{
    this->exam_grade = src.exam_grade;
    this->level = src.level;
    this->level_max = src.level_max;
    this->failures = src.failures;
    this->student = src.student;
    this->reelmode = src.reelmode;
    this->waiting_time = src.waiting_time;
    this->level_per_ex = src.level_per_ex;
    this->level_per_ex_save = src.level_per_ex_save;
    this->exam_number = src.exam_number;
    this->start_time = src.start_time;
    this->end_time = src.end_time;
    this->time_max = src.time_max;
    this->current_ex = src.current_ex;
    return (*this);
}

exam::exam(exam const &src) {}
exam::~exam(void) {}

void exam::up_lvl(void)
{
    level++;
}

time_t exam::get_end_time(void)
{
    return (end_time);
}

time_t exam::get_start_time(void)
{
    return (start_time);
}

int exam::get_lvl(void)
{
    return (level);
}

int exam::get_exam_number()
{
    return (exam_number);
}