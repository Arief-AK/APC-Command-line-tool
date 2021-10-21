//
// Created by Arief on 10/21/2021.
//

#ifndef COMMAND_LINE_TOOL_INT_OPTION_H
#define COMMAND_LINE_TOOL_INT_OPTION_H

#include "../inc/option.h"

namespace lib{
    class int_option : public options::option{
    public:

        // Using the parent's constructor
        using options::option;

        // virtual method for help as different option have different help
        virtual std::string help() const override;

        // Virtual method to check if option requires to parser its arguments
        virtual bool parseable(const char* arg) const override;

        // Virtual method to inject an argument to parse
        virtual std::unique_ptr<arguments::iargument> parse(const char* arg) const override;
};

}

#endif //COMMAND_LINE_TOOL_INT_OPTION_H
