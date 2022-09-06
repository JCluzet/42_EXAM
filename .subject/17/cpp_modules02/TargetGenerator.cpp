#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator it_begin = this->arr_target.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->arr_target.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->arr_target.clear();
}

void TargetGenerator::learnTargetType(ATarget* target_ptr)
{
    if (target_ptr)
        arr_target.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &target_name)
{
    arr_target.erase(target_name);
}

ATarget* TargetGenerator::createTarget(const std::string &target_name)
{
    std::map<std::string, ATarget *>::iterator it = arr_target.find(target_name);
    if (it != arr_target.end())
        return arr_target[target_name];
    return NULL;
}
