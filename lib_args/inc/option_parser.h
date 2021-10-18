//
// Created by Arief on 10/18/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_PARSER_H
#define COMMAND_LINE_TOOL_OPTION_PARSER_H

#include "../inc/option.h"
#include "../inc/interfaces/iargument.h"

namespace lib{
    class option_parser{
    public:
        std::vector<std::unique_ptr<arguments::iargument>> parse_option(char *args[], int nargs) const;
    private:
        std::vector<std::unique_ptr<options::option>> m_options;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_PARSER_H
