//
// Created by Arief on 10/7/2021.
//

#ifndef COMMAND_LINE_TOOL_FLAG_OPTION_H
#define COMMAND_LINE_TOOL_FLAG_OPTION_H

#include "ioption_parser.h"

namespace lib{
class flag_option : public options::ioption_parser{
public:
    // Constructor that calls the 'make_option' function
    flag_option();

    // Makes an option with all properties passed as arguments. Specify the positional arguments if any
    virtual flag_option& make_option(char short_flag, std::string long_flag, std::string description, parameter_type type) override;

    virtual void parse() override;

private:
    char m_short_flag;            // simple char flag for option, e.g. 'h' for help
    std::string m_long_flag;      // long flag format for option, e.g. "help"
    std::string m_description;    // option description

    // TODO: Add a member variable if positional arguments exists
};
}

#endif //COMMAND_LINE_TOOL_FLAG_OPTION_H
