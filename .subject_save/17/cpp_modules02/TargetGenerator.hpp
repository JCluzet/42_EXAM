#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *> arr_target;

        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target_ptr);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &name);
};