#include "exam.hpp"

std::string current_path(void)
{
    std::string current_path = getcwd(NULL, 0);
    if (current_path.find(getenv("HOME")) != std::string::npos)
        current_path.replace(current_path.find(getenv("HOME")), std::string(getenv("HOME")).length(), "~");
    return (current_path);
}

std::string time_in_string(time_t rawtime)
{
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H:%M:%S", timeinfo);
    std::string str(buffer);

    return (str);
}

std::string remaining_time(time_t end_time)
{
    time_t now = time(0);
    time_t remaining_time = end_time - now;
    if (remaining_time < 0)
        return ("0");
    int hours = remaining_time / 3600;
    int minutes = (remaining_time % 3600) / 60;
    int seconds = (remaining_time % 3600) % 60;
    std::stringstream ss;
    ss << hours << "hrs, " << std::setw(2) << minutes << "min and " << std::setw(2) << seconds << "sec";
    return (ss.str());
}

void sigd(void)
{
    std::cout << std::endl << "You have been disconnected after use Ctrl+D" << std::endl;
    exit(0);
}

void sigc(int sig)
{
    std::cout << WHITE << BOLD << std::endl << "Exit exam..." << std::endl;
    exit(0);
}

bool file_exists(std::string path)
{
    std::ifstream infile(path);
    return infile.good();
}

// ==> Reset folder to default
bool exam::clean_all()
{
    if (file_exists("rendu"))
        system("rm -rf rendu");
    if (file_exists("subjects"))
        system("rm -rf subjects");
    if (file_exists(".system/grading"))
        system("rm -rf .system/grading");
    if (file_exists(".system/grading/passed"))
        system("rm -rf .system/grading/passed");
    if (file_exists(".dev"))
        system("rm -f .dev");
    return (true);
}

void reset_folder(void)
{
    system("rm -rf .system/grading/*");
    system("rm -rf rendu/*");
    system("rm -rf subject");
    system("rm -rf traces");
    system("rm -rf a.out");
    system("rm -rf a.out.dSYM");
}